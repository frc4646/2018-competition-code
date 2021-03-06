#include <Commands/Drive/HandleMecanumDrive.h>
#include "MecanumDriveTrain.h"
#include <PinEnums.h>
#include "LOOP/IDriveTrain.h"
#include <cmath>
#include <LOOP/PID.h>
#include <WPILib.h>
#include <Encoder.h>
#include <Subsystems/EncoderChannels.h>
#include <Subsystems/PID4646.h>
#include <Config.h>
#include <iterator>
#include <list>
#include <iostream>
#include <Config.h>
#include <ADXRS450_Gyro.h>
#define PI 3.141592

using namespace loop;

MecanumDriveTrain::MecanumDriveTrain(MotorPin frontLeftPin, MotorPin frontRightPin, MotorPin backLeftPin, MotorPin backRightPin, EncoderChannels frontLeftEncoder, EncoderChannels frontRightEncoder, EncoderChannels backLeftEncoder, EncoderChannels backRightEncoder) :
	IDriveTrain("MecanumDrive"),
	fl(frontLeftPin),
	fr(frontRightPin),
	bl(backLeftPin),
	br(backRightPin),
	flEnc(frontLeftEncoder.a, frontLeftEncoder.b, false, Config::drivetrainEncodingType),
	frEnc(frontRightEncoder.a, frontRightEncoder.b, false, Config::drivetrainEncodingType),
	blEnc(backLeftEncoder.a, backLeftEncoder.b, false, Config::drivetrainEncodingType),
	brEnc(backRightEncoder.a, backRightEncoder.b, false, Config::drivetrainEncodingType),
	gyro(),
	flEncPID(),
	frEncPID(),
	blEncPID(),
	brEncPID(),
	runMotorsToTarget(false),
	angleHoldOverride(false) {
#ifdef PRACTICE_BOT
	gyro.Calibrate();
#endif

	fl.SetSafetyEnabled(false);
	fr.SetSafetyEnabled(false);
	bl.SetSafetyEnabled(false);
	br.SetSafetyEnabled(false);
	fl.SetInverted(true);
	bl.SetInverted(true);

	if (!frc::Preferences::GetInstance()->ContainsKey("MDT-P")) {
		frc::Preferences::GetInstance()->PutDouble("MDT-P", defaultP);
	}
	frc::SmartDashboard::PutNumber("Max Command", defaultMaxCommand);
	frc::SmartDashboard::PutNumber("Min Command", defaultMinCommand);
	frc::SmartDashboard::PutNumber("Delta Degree", deltaDegree);
	frc::SmartDashboard::PutBoolean("Heading Targeting", false);
	frc::SmartDashboard::PutNumber("Target", 0);
	frc::SmartDashboard::PutBoolean("Joystick Targeting Control", true);

	doAngleHold = false;
	angleHoldTarget = 0;
	lastCartR = 0;
	doTracking = false;
	trackingAngle = 0;
	targetMet = true;

	//MLL - Should we make sure all of our encoders are reset?
	// Done. -Christopher; (2/12/18)

	flEnc.Reset();
	frEnc.Reset();
	blEnc.Reset();
	brEnc.Reset();
	frEnc.SetDistancePerPulse(Config::drivetrainDistancePerEncoderTick);
	flEnc.SetDistancePerPulse(Config::drivetrainDistancePerEncoderTick);
	blEnc.SetDistancePerPulse(Config::drivetrainDistancePerEncoderTick);
	brEnc.SetDistancePerPulse(Config::drivetrainDistancePerEncoderTick);
	flEnc.SetReverseDirection(Config::encoderReversalMap & 0b1000);
	frEnc.SetReverseDirection(Config::encoderReversalMap & 0b0100);
	blEnc.SetReverseDirection(Config::encoderReversalMap & 0b0010);
	brEnc.SetReverseDirection(Config::encoderReversalMap & 0b0001);
	gyro.Reset();

	if (!frc::Preferences::GetInstance()->ContainsKey("MDT-FLP")) {
		frc::Preferences::GetInstance()->PutDouble("MDT-FLP", defaultFlTunings.P_Gain);
	}
	if (!frc::Preferences::GetInstance()->ContainsKey("MDT-FRP")) {
		frc::Preferences::GetInstance()->PutDouble("MDT-FRP", defaultFrTunings.P_Gain);
	}
	if (!frc::Preferences::GetInstance()->ContainsKey("MDT-BLP")) {
		frc::Preferences::GetInstance()->PutDouble("MDT-BLP", defaultBlTunings.P_Gain);
	}
	if (!frc::Preferences::GetInstance()->ContainsKey("MDT-BRP")) {
		frc::Preferences::GetInstance()->PutDouble("MDT-BRP", defaultBrTunings.P_Gain);
	}
	defaultFlTunings.P_Gain = frc::Preferences::GetInstance()->GetDouble("MDT-FLP", defaultFlTunings.P_Gain);
	defaultFrTunings.P_Gain = frc::Preferences::GetInstance()->GetDouble("MDT-FRP", defaultFrTunings.P_Gain);
	defaultBlTunings.P_Gain = frc::Preferences::GetInstance()->GetDouble("MDT-BLP", defaultBlTunings.P_Gain);
	defaultBrTunings.P_Gain = frc::Preferences::GetInstance()->GetDouble("MDT-BRP", defaultBrTunings.P_Gain);

	flEncPID.SetTolerance(4.0);
	frEncPID.SetTolerance(4.0);
	blEncPID.SetTolerance(4.0);
	brEncPID.SetTolerance(4.0);

	flEncPID.SetController(defaultFlTunings);
	frEncPID.SetController(defaultFrTunings);
	blEncPID.SetController(defaultBlTunings);
	brEncPID.SetController(defaultBrTunings);
}

void MecanumDriveTrain::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
	SetDefaultCommand(new HandleMecanumDrive());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void MecanumDriveTrain::Stop() {
	fl.Set(0.0);
	fr.Set(0.0);
	bl.Set(0.0);
	br.Set(0.0);
}

void MecanumDriveTrain::Drive(SDriveData driveData) {
	double r = hypot(driveData.cartX, driveData.cartY);
	double theta = atan2(driveData.cartY, driveData.cartX) + (0.5 * PI);
	double p = frc::Preferences::GetInstance()->GetDouble("P", defaultP);
	double maxCommand = frc::SmartDashboard::GetNumber("Max Command", defaultMaxCommand);
	double minCommand = frc::SmartDashboard::GetNumber("Min Command", defaultMinCommand);
	double delta = frc::SmartDashboard::GetNumber("Delta Degree", deltaDegree);
	if (std::fabs(driveData.cartR) > cartRDeadband) {
		if (std::fabs(lastCartR) <= cartRDeadband) {
			// We're manually rotating the robot, so don't doAngleHold.
			doAngleHold = false;
		}
		gyro.Reset();
	} else if (std::fabs(driveData.cartR) <= cartRDeadband && std::fabs(lastCartR) > cartRDeadband) {
		// We're within the deadzone so doAngleHold.
		doAngleHold = true;
		angleHoldTarget = GetGyroAngle();
	}

	double error = 0;//(gyro.GetAngle() - trackingAngle);
	if (doTracking) {
		error = (GetGyroAngle() - trackingAngle);
	} else if (doAngleHold) {
		error = (GetGyroAngle() - angleHoldTarget);
	}
	double motorCommand;
	/*
	if (std::fabs(driveData.cartX) < 0.1 && std::fabs(driveData.cartY) < 0.1 && std::fabs(driveData.cartR) < 0.1 && !runMotorsToTarget){
		Stop();
		return;
	}*/
	//if targeting is on, run P loop math
	if (doTracking || (doAngleHold && angleHoldOverride) ) {
		//Get updated values from the dashboard if needed.

		// During Stronghold season, at CowTown, we found that std::abs is for
		// integers, so it messed up our autonomous. We fixed it by changing it
		// to std::fabs.
		if (std::fabs(error) < delta){
			//std::cout << "Inside deadband" << std::endl;
			//close enough to target so turn off command
			motorCommand = 0;
			targetMet = true;
		}
		else{
			//need to move the robot
			motorCommand = p * error;
			if (motorCommand > maxCommand){
				motorCommand = maxCommand;
			}
			else if ((motorCommand < minCommand) && (motorCommand > 0)){
				motorCommand = minCommand;
			}
			else if((motorCommand > -minCommand) && (motorCommand < 0)){
				motorCommand = -minCommand;
			}
			else if (motorCommand < -maxCommand){
				motorCommand = -maxCommand;
			}
			targetMet = false;
		}
		//std::cout << "Motor command: " << motorCommand << std::endl;

		driveData.cartR = motorCommand;
		frc::SmartDashboard::PutNumber("CartR", driveData.cartR);
		frc::SmartDashboard::PutNumber("Err", error);
	}

	//frc::SmartDashboard::PutNumber("X Gyro", gyro.GetAngleX());
	//frc::SmartDashboard::PutNumber("Y Gyro", gyro.GetAngleY());
	frc::SmartDashboard::PutNumber("Z Gyro", GetGyroAngle());
	frc::SmartDashboard::PutData("Gyro Data", &gyro);
	frc::SmartDashboard::PutNumber("Gyro heading", GetGyroAngle());

	if (runMotorsToTarget) {
#ifdef PRACTICE_BOT
		double brPower = -brEncPID.UpdateControl(GetEncoderDistance(EncoderIndex::BACK_RIGHT));
		fl.Set(brPower + driveData.cartR);
		br.Set(brPower - driveData.cartR);
#else
		fl.Set(-flEncPID.UpdateControl(GetEncoderDistance(EncoderIndex::FRONT_LEFT) + driveData.cartR));
		br.Set(-brEncPID.UpdateControl(GetEncoderDistance(EncoderIndex::BACK_RIGHT) - driveData.cartR));
#endif
		fr.Set(-frEncPID.UpdateControl(GetEncoderDistance(EncoderIndex::FRONT_RIGHT) - driveData.cartR));
		bl.Set(-blEncPID.UpdateControl(GetEncoderDistance(EncoderIndex::BACK_LEFT) + driveData.cartR));
	} else {
		fl.Set(r * sin(theta + (PI / 4)) + driveData.cartR);
		fr.Set(r * cos(theta + (PI / 4)) - driveData.cartR);
		bl.Set(r * cos(theta + (PI / 4)) + driveData.cartR);
		br.Set(r * sin(theta + (PI / 4)) - driveData.cartR);
	}

	lastCartR = driveData.cartR;
}


void MecanumDriveTrain::EnableTracking(bool enable) {
	doTracking = enable;
}

bool MecanumDriveTrain::TrackingEnabled() {
	return doTracking;
}

void MecanumDriveTrain::SetAngleTrackingTarget(double angle) {
	trackingAngle = angle;
	targetMet = false;
}

bool MecanumDriveTrain::AngleTrackingTargetMet() {
	return targetMet;
}

void MecanumDriveTrain::ResetEncoders() {
	flEnc.Reset();
	frEnc.Reset();
	blEnc.Reset();
	brEnc.Reset();
}

double MecanumDriveTrain::GetEncoderDistance(EncoderIndex whichEncoder){
	switch (whichEncoder) {
		case EncoderIndex::FRONT_LEFT:
			return flEnc.GetDistance();
		case EncoderIndex::FRONT_RIGHT:
			return frEnc.GetDistance();
		case EncoderIndex::BACK_LEFT:
			return blEnc.GetDistance();
		case EncoderIndex::BACK_RIGHT:
			return brEnc.GetDistance();
		default:
			return 0;
	}
}

int MecanumDriveTrain::GetEncoderRaw(EncoderIndex whichEncoder){
	switch (whichEncoder) {
		case EncoderIndex::FRONT_LEFT:
			return flEnc.GetRaw();
		case EncoderIndex::FRONT_RIGHT:
			return frEnc.GetRaw();
		case EncoderIndex::BACK_LEFT:
			return blEnc.GetRaw();
		case EncoderIndex::BACK_RIGHT:
			return brEnc.GetRaw();
		default:
			return 0;
	}
}

void MecanumDriveTrain::SetEncoderTarget(EncoderIndex whichEncoder, double target) {
	if (whichEncoder & EncoderIndex::FRONT_LEFT) {
		flEncPID.SetTarget(target);
	}
	if (whichEncoder & EncoderIndex::FRONT_RIGHT) {
		frEncPID.SetTarget(target);
	}
	if (whichEncoder & EncoderIndex::BACK_LEFT) {
		blEncPID.SetTarget(target);
	}
	if (whichEncoder & EncoderIndex::BACK_RIGHT) {
		brEncPID.SetTarget(target);
	}
}

double MecanumDriveTrain::GetEncoderTarget(EncoderIndex whichEncoder) {
	return (*PIDForIndex(whichEncoder))->GetTarget();
}

void MecanumDriveTrain::EnableRunToPosition(bool enable) {
	runMotorsToTarget = enable;
}

bool MecanumDriveTrain::RunToPositionEnabled() {
	return runMotorsToTarget;
}

bool MecanumDriveTrain::EncodersAtTarget(EncoderIndex whichEncoder) {
	bool ret = true;


	if (whichEncoder & EncoderIndex::FRONT_LEFT) {
		ret &= flEncPID.AtTarget();
	}
	if (whichEncoder & EncoderIndex::FRONT_RIGHT) {
		ret &= frEncPID.AtTarget();
	}
	if (whichEncoder & EncoderIndex::BACK_LEFT) {
		ret &= blEncPID.AtTarget();
	}
	if (whichEncoder & EncoderIndex::BACK_RIGHT) {
		ret &= brEncPID.AtTarget();
	}

	return ret;
}

std::list<Encoder*>::iterator MecanumDriveTrain::EncoderForIndex(EncoderIndex whichEncoder) {
	std::list<Encoder*> l;
	if (whichEncoder & EncoderIndex::FRONT_LEFT) {
		l.push_back(&flEnc);
	}
	if (whichEncoder & EncoderIndex::FRONT_RIGHT) {
		l.push_back(&frEnc);
	}
	if (whichEncoder & EncoderIndex::BACK_LEFT) {
		l.push_back(&blEnc);
	}
	if (whichEncoder & EncoderIndex::BACK_RIGHT) {
		l.push_back(&brEnc);
	}
	return l.begin();
}

std::list<PID4646*>::iterator MecanumDriveTrain::PIDForIndex(EncoderIndex whichEncoder) {
	std::list<PID4646*> l;
	if (whichEncoder & EncoderIndex::FRONT_LEFT) {
		l.push_back(&flEncPID);
	}
	if (whichEncoder & EncoderIndex::FRONT_RIGHT) {
		l.push_back(&frEncPID);
	}
	if (whichEncoder & EncoderIndex::BACK_LEFT) {
		l.push_back(&blEncPID);
	}
	if (whichEncoder & EncoderIndex::BACK_RIGHT) {
		l.push_back(&brEncPID);
	}
	return l.begin();
}

void MecanumDriveTrain::ResetEncoderPIDs() {
	flEncPID.ResetControl();
	frEncPID.ResetControl();
	blEncPID.ResetControl();
	brEncPID.ResetControl();
}

void MecanumDriveTrain::DumpEncoderValues() {
	frc::SmartDashboard::PutNumber("FLR", flEnc.GetRaw());
	frc::SmartDashboard::PutNumber("FRR", frEnc.GetRaw());
	frc::SmartDashboard::PutNumber("BLR", blEnc.GetRaw());
	frc::SmartDashboard::PutNumber("BRR", brEnc.GetRaw());
}

void MecanumDriveTrain::EnableAngleHold(bool enabled) {
	angleHoldOverride = enabled;
}

double MecanumDriveTrain::GetGyroAngle() {
#ifdef PRACTICE_BOT
	return -gyro.GetAngle();
#else
	return gyro.GetAngleZ();
#endif
}

void MecanumDriveTrain::ResetGyro() {
	gyro.Reset();
}

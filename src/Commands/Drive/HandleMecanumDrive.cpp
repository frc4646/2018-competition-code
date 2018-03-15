#include "HandleMecanumDrive.h"
#include <LOOP/IDriveTrain.h>
#include <LOOP/Utils.h>
#include <config.h>
#include <iostream>

using namespace loop;
#if (DRIVETRAIN == MecanumDriveTrain)
HandleMecanumDrive::HandleMecanumDrive() : CommandBase("HandleDrive"), joyDB(0.1), joytar(false) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires((frc::Subsystem*) drivetrain.get());
	frc::SmartDashboard::PutNumber("Joystick Deadband", defaultJoyDB);
	if (!frc::Preferences::GetInstance()->ContainsKey("HMD-cartRDeadband")) {
		frc::Preferences::GetInstance()->PutDouble("HMD-cartRDeadband", 0.1);
	}
}

// Called just before this Command runs the first time
void HandleMecanumDrive::Initialize() {

}

// Called repeatedly when this Command is scheduled to run

void HandleMecanumDrive::Execute() {

	frc::SmartDashboard::PutNumber("FL", drivetrain->GetEncoderDistance(MecanumDriveTrain::EncoderIndex::FRONT_LEFT));
	frc::SmartDashboard::PutNumber("FR", drivetrain->GetEncoderDistance(MecanumDriveTrain::EncoderIndex::FRONT_RIGHT));
	frc::SmartDashboard::PutNumber("BL", drivetrain->GetEncoderDistance(MecanumDriveTrain::EncoderIndex::BACK_LEFT));
	frc::SmartDashboard::PutNumber("BR", drivetrain->GetEncoderDistance(MecanumDriveTrain::EncoderIndex::BACK_RIGHT));
	drivetrain->DumpEncoderValues();

	//build drive data
	SDriveData driveData;
	driveData.cartX = oi->GetRightJoystickX();
	driveData.cartY = oi->GetRightJoystickY();
	driveData.cartR = oi->GetLeftJoystickX();

	//get more values from SD
	drivetrain->EnableTracking(frc::SmartDashboard::GetBoolean("Heading Targeting", false));
	joytar = frc::SmartDashboard::GetBoolean("Joystick Targeting Control", false);
	joyDB = frc::SmartDashboard::GetNumber("Joystick Deadband", defaultJoyDB);
	double target = frc::SmartDashboard::GetNumber("Target", 0);
	double cartRDeadband = frc::Preferences::GetInstance()->GetDouble("HMD-cartRDeadband");

	//deadband rotation joystick and change error variable if necessary
	if ((oi->GetLeftJoystickX() * (oi->GetLeftJoystickThrottle() * -1.0) > joyDB || oi->GetLeftJoystickX() * (oi->GetLeftJoystickThrottle() * -1.0) < -joyDB) && joytar){
		target -= (oi->GetLeftJoystickX() * ((3.0)/(1+joyDB)));
		// * 4 is for 180 degree rotation per second.
		//Only update these numbers if there has been a change
		drivetrain->SetAngleTrackingTarget(target);
		frc::SmartDashboard::PutNumber("Target", target);
	}

	// When setting driveData, multiply it by the appropriate throttle axis on each of the joysticks so we can
	// set specific speeds.
	driveData.cartX = (driveData.cartX*(oi->GetRightJoystickThrottle()*-1));
	driveData.cartY = (driveData.cartY*(oi->GetRightJoystickThrottle()*-1));
	if (driveData.cartX > 0.1) {
		drivetrain->EnableAngleHold(true);
	} else {
		drivetrain->EnableAngleHold(false);
	}
	driveData.cartR = loop::applyDeadband((driveData.cartR * (oi->GetLeftJoystickThrottle() * -1.0)), cartRDeadband);
	drivetrain->Drive(driveData);

}

// Make this return true when this Command no longer needs to run execute()
bool HandleMecanumDrive::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void HandleMecanumDrive::End() {
	drivetrain->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void HandleMecanumDrive::Interrupted() {
	End();
}
#endif


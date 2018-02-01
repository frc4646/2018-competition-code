#include <Commands/HandleMecanumDrive.h>
#include "MecanumDriveTrain.h"
#include <PinEnums.h>
#include "LOOP/IDriveTrain.h"
#include <cmath>
#include <LOOP/PID.h>
#include <WPILib.h>
#define PI 3.141592

using namespace loop;

MecanumDriveTrain::MecanumDriveTrain(MotorPin frontLeftPin, MotorPin frontRightPin, MotorPin backLeftPin, MotorPin backRightPin) :
	IDriveTrain("MecanumDrive"),
	fl(frontLeftPin),
	fr(frontRightPin),
	bl(backLeftPin),
	br(backRightPin){

	fl.SetSafetyEnabled(false);
	fr.SetSafetyEnabled(false);
	bl.SetSafetyEnabled(false);
	br.SetSafetyEnabled(false);
	fl.SetInverted(true);
	bl.SetInverted(true);

	frc::SmartDashboard::PutNumber("P", defaultP);
	frc::SmartDashboard::PutNumber("Max Command", defaultMaxCommand);
	frc::SmartDashboard::PutNumber("Min Command", defaultMinCommand);
	frc::SmartDashboard::PutNumber("Delta Degree", deltaDegree);
	frc::SmartDashboard::PutBoolean("Heading Targeting", false);
	frc::SmartDashboard::PutNumber("Target", 0);
	frc::SmartDashboard::PutBoolean("Joystick Targeting Control", true);

	doTracking = true;
	trackingAngle = 0;
	targetMet = true;

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

void MecanumDriveTrain::DoDrive(SDriveData driveData) {
	double p = frc::SmartDashboard::GetNumber("P", defaultP);
	double maxCommand = frc::SmartDashboard::GetNumber("Max Command", defaultMaxCommand);
	double minCommand = frc::SmartDashboard::GetNumber("Min Command", defaultMinCommand);
	double delta = frc::SmartDashboard::GetNumber("Delta Degree", deltaDegree);
	double error = (gyro.GetAngleZ() - trackingAngle);
	double motorCommand;
	double r = hypot(driveData.cartX, driveData.cartY);
	double theta = atan2(driveData.cartY, driveData.cartX) + (0.5 * PI);

	//if targeting is on, run P loop math
	if (doTracking) {
		//Get updated values from the dashboard if needed.

		if (std::abs(error) < delta){
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
		}

		driveData.cartR = motorCommand;
		frc::SmartDashboard::PutNumber("CartR", driveData.cartR);
		frc::SmartDashboard::PutNumber("Err", error);
	}

	frc::SmartDashboard::PutNumber("X Gyro", gyro.GetAngleX());
	frc::SmartDashboard::PutNumber("Y Gyro", gyro.GetAngleY());
	frc::SmartDashboard::PutNumber("Z Gyro", gyro.GetAngleZ());
	frc::SmartDashboard::PutData("Gyro Data", &gyro);
	frc::SmartDashboard::PutNumber("Gyro heading", gyro.GetAngle());

	fl.Set(r * sin(theta + (PI / 4)) + driveData.cartR);
	fr.Set(r * cos(theta + (PI / 4)) - driveData.cartR);
	bl.Set(r * cos(theta + (PI / 4)) + driveData.cartR);
	br.Set(r * sin(theta + (PI / 4)) - driveData.cartR);
}


void MecanumDriveTrain::EnableTracking(bool enable)
{
	doTracking = enable;
}

bool MecanumDriveTrain::TrackingEnabled()
{
	return doTracking;
}

void MecanumDriveTrain::SetAngleTrackingTarget(double angle)
{
	trackingAngle = angle;
	targetMet = false;
}

bool MecanumDriveTrain::AngleTrackingTargetMet()
{
	return targetMet;
}


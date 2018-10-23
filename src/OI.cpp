#include "OI.h"

#include <WPILib.h>
#include "Config.h"
#include "Commands/Drive/ResetDrivetrainEncoders.h"
#include "Commands/Drive/HandleMecanumDrive.h"
#include "Commands/Intake/OuttakePowerCube.h"
#include "Commands/Intake/IntakePowerCube.h"
#include "Commands/Drive/DriveToPoint.h"
#include "Commands/TestCommands/TestDriveToPoint.h"
#include "Commands/Drive/ResetGyro.h"
#include "AutoCommands/AutonomousCommands/DriveSidewaysForDistance.h"
#include "AutoCommands/AutonomousCommands/DriveAndSwitch.h"
#include <Commands/Drive/RotateToPoint.h>
#include <Commands/Lift/LiftToScale.h>
#include <Commands/Lift/LiftToFloor.h>

using namespace loop;

OI::OI() :
	left(0),
	right(1),
	mechanism(2),
	gamepad(3),
	straightDrive(&right, 1),
	intake(&mechanism, 11),
	outtake(&mechanism, 9)
	//driveToPoint(&mechanism, 12)
	{
}

void OI::Init() {
	// Anything that requires a subystem goes here.
	// Anonymous implementation of straight drive.
	// Works fine for tele-op, but not for auto.

	//frc::SmartDashboard::PutData("Reset Encoders", new ResetDrivetrainEncoders());
	frc::SmartDashboard::PutData(new LiftToScale());
	frc::SmartDashboard::PutData(new DriveToPoint(0, 60));
	frc::SmartDashboard::PutData(new ResetGyro());
	frc::SmartDashboard::PutData(new DriveSidewaysForDistance(75));
	frc::SmartDashboard::PutData(new LiftToFloor());

	//frc::SmartDashboard::PutData(new DriveAndSwitch(-70));
	frc::SmartDashboard::PutData(new RotateToPoint(45));
	//driveToPoint.WhenPressed(new DriveToPoint(0, 60));
	intake.WhileHeld(new IntakePowerCube());
	outtake.WhileHeld(new OuttakePowerCube());

	frc::SmartDashboard::PutData(new ResetDrivetrainEncoders());
}

// Since I don't have an F310 and the driver station with me, I'm making assumptions about axis numbering
double OI::GetLeftJoystickX() {
//return gamepad.GetRawAxis(0)*0.6;
	return left.GetRawAxis(0)*-1;
}
double OI::GetRightJoystickThrottle() {
	return right.GetRawAxis(2);
}
double OI::GetLeftJoystickThrottle() {
	return left.GetRawAxis(2);
}
bool OI::GetMechanismTrigger(){
	return mechanism.GetTrigger();
}

double OI::GetLeftJoystickY() {
	return left.GetRawAxis(1)*-1;
}

double OI::GetRightJoystickX() {
	return right.GetRawAxis(0)*-1;
}

double OI::GetRightJoystickY() {
	return right.GetRawAxis(1)*-1;
}

double OI::GetMechanismY() {
	return mechanism.GetRawAxis(1)*-1;
}

Joystick& OI::GetMechanism() {
	return mechanism;
}

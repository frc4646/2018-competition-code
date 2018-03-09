#include "OI.h"

#include <WPILib.h>
#include "Config.h"
#include "Commands/Drive/ResetDrivetrainEncoders.h"
#include "Commands/Drive/HandleMecanumDrive.h"
#include "Commands/Intake/OuttakePowerCube.h"
#include "Commands/Intake/IntakePowerCube.h"
#include "Commands/Drive/DriveToPoint.h"

using namespace loop;

OI::OI() :
#ifndef GAMEPAD
	left(0),
	right(1),
	mechanism(2),
#else
	gamepad(0),
#endif
	straightDrive(&right, 1),
	intake(&mechanism, 11),
	outtake(&mechanism, 9),
	driveToPoint(&mechanism, 12)
	{
}

void OI::Init() {
	// Anything that requires a subystem goes here.
	// Anonymous implementation of straight drive.
	// Works fine for tele-op, but not for auto.

	//frc::SmartDashboard::PutData("Reset Encoders", new ResetDrivetrainEncoders());
	//frc::SmartDashboard::PutData("Drive to point", new TestDriveToPoint(frc::Vector2d(0, 60)));
	driveToPoint.WhenPressed(new DriveToPoint(0, 60));
	intake.WhileHeld(new IntakePowerCube());
	outtake.WhileHeld(new OuttakePowerCube());
}

// Since I don't have an F310 and the driver station with me, I'm making assumptions about axis numbering
double OI::GetLeftJoystickX() {
#ifndef GAMEPAD
	return left.GetRawAxis(0) * -1.0;
#else
	return gamepad.GetRawAxis(0) * -1.0;
#endif
}
double OI::GetRightJoystickThrottle() {
#ifndef GAMEPAD
	return right.GetRawAxis(2);
#endif
}
double OI::GetLeftJoystickThrottle() {
#ifndef GAMEPAD
	return left.GetRawAxis(2);
#endif
}
bool OI::GetMechanismTrigger(){
#ifndef GAMEPAD
	return mechanism.GetTrigger();
#endif
}

double OI::GetLeftJoystickY() {
#ifndef GAMEPAD
	return left.GetRawAxis(1) * -1.0;
#else
	return gamepad.GetRawAxis(1) * -1.0;
#endif
}

double OI::GetRightJoystickX() {
#ifndef GAMEPAD
	return right.GetRawAxis(0) * -1.0;
#else
	return gamepad.GetRawAxis(4) * -1.0;
#endif
}

double OI::GetRightJoystickY() {
#ifndef GAMEPAD
	return right.GetRawAxis(1) * -1.0;
#else
	return gamepad.GetRawAxis(5) * -1.0;
#endif
}

#ifndef GAMEPAD
double OI::GetMechanismX() {
	return mechanism.GetRawAxis(0) * -1.0;
}

double OI::GetMechanismY() {
	return mechanism.GetRawAxis(1) * -1.0;
}

double OI::GetMechanismZ() {
	return mechanism.GetRawAxis(2) * -1.0;
}

Joystick& OI::GetMechanism() {
	return mechanism;
}
#endif


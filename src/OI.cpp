#include "OI.h"

#include <WPILib.h>
#include "Config.h"
#include <LOOP/Binding.h>
#include "Commands/HandleMecanumDrive.h"

using namespace loop;

OI::OI() :
#ifndef GAMEPAD
	left(0),
	right(1),
	mechanism(2),
#else
	gamepad(0),
#endif
	straightDrive(&right, 1)
	{
	// Process operator interface input here.
	// Anonymous implementation of straight drive.
	// Works fine for tele-op, but not for auto.
	/*straightDrive.WhenPressed(new Binding(
		[]() {
			HandleMecanumDrive::target = CommandBase::drivetrain->GetAngle();
			HandleMecanumDrive::trackTarget = true;
		},
		[]() {

		},
		[]() {
			HandleMecanumDrive::trackTarget = false;
		},
		1,
		CommandBase::drivetrain.get()
	));*/
}

// Since I don't have an F310 and the driver station with me, I'm making assumptions about axis numbering
double OI::GetLeftJoystickX() {
#ifndef GAMEPAD
	return left.GetRawAxis(0) * -1.0;
#else
	return gamepad.GetRawAxis(0) * -1.0;
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
#endif

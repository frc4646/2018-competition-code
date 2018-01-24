#ifndef OI_H
#define OI_H

#include "Config.h"
#include <Wpilib.h>

class OI {
public:
	OI();
	double GetLeftJoystickX();
	double GetLeftJoystickY();
	double GetRightJoystickX();
	double GetRightJoystickY();
#ifndef GAMEPAD
	double GetMechanismX();
	double GetMechanismY();
	double GetMechanismZ();
#endif
private:
#ifndef GAMEPAD
	Joystick left;
	Joystick right;
	Joystick mechanism;
#else
	Joystick gamepad;
#endif
	JoystickButton straightDrive;
};

#endif  // OI_H

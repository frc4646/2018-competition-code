#ifndef OI_H
#define OI_H

#include "Config.h"
#include <Wpilib.h>

class OI {
public:
	OI();
	void Init();
	double GetLeftJoystickX();
	double GetLeftJoystickY();
	double GetRightJoystickX();
	double GetRightJoystickY();
	double GetLeftJoystickThrottle();
	double GetRightJoystickThrottle();
	bool GetMechanismTrigger();
#ifndef GAMEPAD
	double GetMechanismX();
	double GetMechanismY();
	double GetMechanismZ();
	Joystick& GetMechanism();
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
	JoystickButton intake;
	JoystickButton outtake;
	//JoystickButton driveToPoint;
};

#endif  // OI_H

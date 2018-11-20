#ifndef OI_H
#define OI_H

#include "Config.h"
#include <frc/Wpilib.h>

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
	frc::Joystick& GetMechanism();
#endif
private:
	frc::Joystick left;
	frc::Joystick right;
	frc::Joystick mechanism;
	frc::Joystick gamepad;
	frc::JoystickButton straightDrive;
	frc::JoystickButton intake;
	frc::JoystickButton outtake;
	//JoystickButton driveToPoint;
};

#endif  // OI_H

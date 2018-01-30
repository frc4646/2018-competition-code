#ifndef ClimberLimitSwitch_H
#define ClimberLimitSwitch_H

#include <Commands/Subsystem.h>
#include "PinEnums.h"
#include <WPILib.h>

class ClimberLimitSwitch : public Subsystem {
private:
	DigitalInput ClimberLimitSwitchPin;

public:
	ClimberLimitSwitch(DIOPin pin);
	void InitDefaultCommand();
	bool IsPressed();
};

#endif  // ClimberLimitSwitch_H

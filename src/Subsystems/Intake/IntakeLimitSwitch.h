#ifndef IntakeLimitSwitch_H
#define IntakeLimitSwitch_H

#include <Commands/Subsystem.h>
#include "PinEnums.h"
#include <WPILib.h>

class IntakeLimitSwitch : public Subsystem {
private:
	DigitalInput IntakeLimitSwitchPin;

public:
	IntakeLimitSwitch(DIOPin pin);
	void InitDefaultCommand();
	bool IsPressed();
};

#endif  // IntakeLimitSwitch_H

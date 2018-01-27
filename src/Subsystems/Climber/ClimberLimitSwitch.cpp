#include "ClimberLimitSwitch.h"
#include <RobotMap.h>

ClimberLimitSwitch::ClimberLimitSwitch(DIOPin pin) : Subsystem("ExampleSubsystem"), ClimberLimitSwitchPin(pin) {
	//ClimberLimitSwitchPin = new DigitalInput(pin);
}

void ClimberLimitSwitch::InitDefaultCommand() {}

bool ClimberLimitSwitch::IsPressed() {
	return ClimberLimitSwitchPin.Get();
}

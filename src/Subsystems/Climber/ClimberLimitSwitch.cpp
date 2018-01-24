#include "ClimberLimitSwitch.h"
#include "../RobotMap.h"

ClimberLimitSwitch::ClimberLimitSwitch(DIOPin pin) : Subsystem("ExampleSubsystem") {
	ClimberLimitSwitchPin = new DigitalInput(pin);
}

void ClimberLimitSwitch::InitDefaultCommand() {}

bool IsPressed() {
	return ClimberLimitSwitchPin->Get();
}

#include "IntakeLimitSwitch.h"
#include "../RobotMap.h"

IntakeLimitSwitch::IntakeLimitSwitch(DIOPin pin) : Subsystem("ExampleSubsystem") {
	IntakeLimitSwitchPin = new DigitalInput(pin);
}

void IntakeLimitSwitch::InitDefaultCommand() {}

bool IsPressed() {
	return IntakeLimitSwitchPin->Get();
}

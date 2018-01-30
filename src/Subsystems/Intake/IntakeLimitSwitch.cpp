#include "IntakeLimitSwitch.h"
#include <RobotMap.h>

IntakeLimitSwitch::IntakeLimitSwitch(DIOPin pin) : Subsystem("ExampleSubsystem"), IntakeLimitSwitchPin(pin) {
	//IntakeLimitSwitchPin = new DigitalInput(pin);
}

void IntakeLimitSwitch::InitDefaultCommand() {}

bool IntakeLimitSwitch::IsPressed() {
	return IntakeLimitSwitchPin.Get();
}

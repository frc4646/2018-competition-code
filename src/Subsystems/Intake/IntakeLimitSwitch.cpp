#include "IntakeLimitSwitch.h"
#include <RobotMap.h>

IntakeLimitSwitch::IntakeLimitSwitch(DIOPin pin) : Subsystem("ExampleSubsystem"), IntakeLimitSwitchPin(pin) {

}

void IntakeLimitSwitch::InitDefaultCommand() {}

bool IntakeLimitSwitch::IsPressed() {
	return IntakeLimitSwitchPin.Get();
}

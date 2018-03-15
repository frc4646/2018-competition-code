#include "LiftStringPot.h"
#include <RobotMap.h>

LiftStringPot::LiftStringPot(int pin) : Subsystem("LiftStringPot"), LiftStringPotPin(pin) {
	//LiftStringPotPin = new AnalogInput(pin);
}

void LiftStringPot::InitDefaultCommand() {}

double LiftStringPot::GetHeight() {
	double height;
	double m;
	double b;

	int value = LiftStringPotPin.GetVoltage(); // @suppress("Invalid arguments")

	m = (MinHeight - MaxHeight) / (double)(MinValue - MaxValue);
	b = MinHeight - ((MinValue)*(m));

	height = ((m)*(value)) + b;

	return height;
	//return LiftStringPotPin.GetVoltage();
}

double LiftStringPot::GetMaxHeight() {
	return MaxHeight;
}

double LiftStringPot::GetMinHeight() {
	return MinHeight;
}

double LiftStringPot::GetSwitchHeight() {
	return SwitchHeight;
}

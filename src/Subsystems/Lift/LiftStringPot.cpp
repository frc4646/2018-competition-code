#include "LiftStringPot.h"
#include "../RobotMap.h"

LiftStringPot::LiftStringPot(AnalogPin pin) : Subsystem("ExampleSubsystem") {
	LiftStringPotPin = new AnalogInput(pin);
}

void LiftStringPot::InitDefaultCommand() {}

double GetHeight() {
	double height;
	double m;
	double b;

	int value = LiftStringPotPin->GetValue();

	m = (MinHeight - MaxHeight) / (double)(MinValue - MaxValue);
	b = MinHeight - (MinValue)(m);

	height = (m)(value) + b;

	return height;
}

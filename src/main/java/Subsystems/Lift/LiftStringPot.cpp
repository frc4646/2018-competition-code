#include "LiftStringPot.h"
#include <RobotMap.h>
#include <Config.h>

LiftStringPot::LiftStringPot(int pin) : Subsystem("LiftStringPot"), LiftStringPotPin(pin) {
	//LiftStringPotPin = new AnalogInput(pin);
}

void LiftStringPot::InitDefaultCommand() {}

double LiftStringPot::GetHeight() {
#ifdef PRACTICE_BOT
	double height;
	double m;
	double b;

	double value = LiftStringPotPin.GetVoltage(); // @suppress("Invalid arguments")

	m = (MinHeight - MaxHeight) / (double)(MinValue - MaxValue);
	b = MinHeight - ((MinValue)*(m));

	height = ((m)*(value)) + b;

	return height;
#else
	return LiftStringPotPin.GetVoltage();
	/*
	double height;
	double m;
	double b;
	double value = LiftStringPotPin.GetVoltage(); // @suppress("Invalid arguments")
	m = (MinHeight - MaxHeight) / (double)(MinValue - MaxValue);
	b = MinHeight - ((MinValue)*(m));
	height = ((m)*(value)) + b;
	return height;
	*/
#endif
}

double LiftStringPot::GetMaxHeight() {
#ifdef PRACTICE_BOT
	return MaxHeight;
#else
	return MaxValue;
	//return MaxHeight;
#endif
}

double LiftStringPot::GetMinHeight() {
#ifdef PRACTICE_BOT
	return MinHeight;
#else
	return MinValue;
	//return MinHeight;
#endif
}

double LiftStringPot::GetSwitchHeight() {
	return SwitchValue;
}

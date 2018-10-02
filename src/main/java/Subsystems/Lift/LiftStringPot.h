#ifndef LiftStringPot_H
#define LiftStringPot_H

#include <Commands/Subsystem.h>
#include "PinEnums.h"
#include <WPILib.h>

class LiftStringPot : public Subsystem {
private:
	const double MinHeight = 0.0;
	const double MaxHeight = 74.0;
	const double SwitchHeight = 24;
	const double MinValue = 1.39;//0;
	const double MaxValue = 4.125;//1023;
	const double SwitchValue = 2.5;
	AnalogInput LiftStringPotPin;

public:
	LiftStringPot(int pin);
	void InitDefaultCommand();
	double GetHeight();
	double GetMaxHeight();
	double GetMinHeight();
	double GetSwitchHeight();
};

#endif  // LiftStringPot_H

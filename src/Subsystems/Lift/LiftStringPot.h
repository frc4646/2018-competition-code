#ifndef LiftStringPot_H
#define LiftStringPot_H

#include <Commands/Subsystem.h>
#include "PinEnums.h"
#include <WPILib.h>

class LiftStringPot : public Subsystem {
private:
	const double MinHeight = 0;
	const double MaxHeight = 4;
	const int MinValue = 0;
	const int MaxValue = 1023;
	AnalogInput LiftStringPotPin;

public:
	LiftStringPot(int pin);
	void InitDefaultCommand();
	double GetHeight();
	double GetMaxHeight();
	double GetMinHeight();
};

#endif  // LiftStringPot_H

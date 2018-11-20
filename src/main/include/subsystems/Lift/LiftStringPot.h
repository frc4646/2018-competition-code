#ifndef LiftStringPot_H
#define LiftStringPot_H

#include <frc/Commands/Subsystem.h>
#include "PinEnums.h"
#include <frc/WPILib.h>

class LiftStringPot : public frc::Subsystem {
private:
	const double MinHeight = 0.0;
	const double MaxHeight = 74.0;
	const double SwitchHeight = 24;
	const double MinValue = 1.39;//0;
	const double MaxValue = 4.125;//1023;
	const double SwitchValue = 2.5;
	frc::AnalogInput LiftStringPotPin;

public:
	LiftStringPot(int pin);
	void InitDefaultCommand();
	double GetHeight();
	double GetMaxHeight();
	double GetMinHeight();
	double GetSwitchHeight();
};

#endif  // LiftStringPot_H

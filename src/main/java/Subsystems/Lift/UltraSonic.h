#ifndef UltraSonic_H
#define UltraSonic_H

#include <Commands/Subsystem.h>
#include "PinEnums.h"
#include <WPILib.h>

class UltraSonic : public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	AnalogInput UltraSonicPin;

public:
	UltraSonic(int pin);
	void InitDefaultCommand();
	double GetVoltage();
	double GetDistance();
	int GetCounts();
};

#endif  // UltraSonic_H

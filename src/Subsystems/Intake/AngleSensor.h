#ifndef AngleSensor_H
#define AngleSensor_H

#include <Commands/Subsystem.h>
#include "PinEnums.h"
#include <WPILib.h>

class AngleSensor : public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	AnalogInput AngleSensorPin;
	const double MinAngle = 0;
	const double MaxAngle = 100;
	const int MinValue = 0;
	const int MaxValue = 1023;
	double m;
	double b;

public:
	AngleSensor(int pin);
	void InitDefaultCommand();
	double GetAngle();
};

#endif  // AngleSensor_H

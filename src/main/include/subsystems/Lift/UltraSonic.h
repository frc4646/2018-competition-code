#ifndef UltraSonic_H
#define UltraSonic_H

#include <frc/Commands/Subsystem.h>
#include <PinEnums.h>
#include <frc/WPILib.h>

class UltraSonic : public frc::Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	frc::AnalogInput UltraSonicPin;

public:
	UltraSonic(int pin);
	void InitDefaultCommand();
	double GetVoltage();
	double GetDistance();
	int GetCounts();
};

#endif  // UltraSonic_H

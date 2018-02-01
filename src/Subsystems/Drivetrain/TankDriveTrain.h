#ifndef TankDrive_H
#define TankDrive_H

#include <Commands/Subsystem.h>
#include <Spark.h>
#include <PinEnums.h>
#include <LOOP/IDriveTrain.h>
#include <LOOP/Binding.h>

using namespace loop;

class TankDriveTrain : public IDriveTrain {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities

	// Only one Spark object is needed per side. It just seems y'all have never head of PWM splitters.
	Spark left, right;
protected:
	void DoDrive(SDriveData driveData);

public:
	TankDriveTrain(MotorPin leftPin, MotorPin rightPin);
	void InitDefaultCommand();
	void Stop();
};

#endif  // TankDrive_H


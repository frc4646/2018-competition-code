#ifndef TankDrive_H
#define TankDrive_H

#include <Commands/Subsystem.h>
#include <Spark.h>
#include <PinEnums.h>
#include <Subsystems/Drivetrain/IDriveTrain.h>
#include <LOOP/Binding.h>

using namespace loop;

class TankDriveTrain : public IDriveTrain {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities

	// Only one Spark object is needed per side. It just seems y'all have never head of PWM splitters.
	Spark frontLeft, frontRight, backLeft, backRight;

public:
	TankDriveTrain(MotorPin frontLeftPin, MotorPin frontRightPin, MotorPin backLeftPin, MotorPin backRightPin);
	void InitDefaultCommand();
	void Stop();
	void Drive(SDriveData driveData);
};

#endif  // TankDrive_H


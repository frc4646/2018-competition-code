<<<<<<< HEAD
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
	Spark left, right;
protected:
	void DoDrive(SDriveData driveData) override;

public:
	TankDriveTrain(MotorPin leftPin, MotorPin rightPin);
	void InitDefaultCommand();
	void Stop();
};

#endif  // TankDrive_H
=======
#ifndef TankDrive_H
#define TankDrive_H

#include <Commands/Subsystem.h>
#include <Spark.h>
#include <PinEnums.h>
#include <Subsystems/Drivetrain/IDriveTrain.h>
#include <LOOP/Binding.h>
#include <WPILib.h>

using namespace loop;

class TankDriveTrain : public IDriveTrain {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities

	// Only one Spark object is needed per side. It just seems y'all have never head of PWM splitters.
	Spark left, right;

public:
	TankDriveTrain(MotorPin leftPin, MotorPin rightPin);
	void InitDefaultCommand();
	void Stop();
	void Drive(SDriveData driveData);
};

#endif  // TankDrive_H
>>>>>>> 7c4ef7586961181d848fb171a63752b73ecdac32

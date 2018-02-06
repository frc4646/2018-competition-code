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
	/*
	 * Response to whoever typed this,
	 * On Percy we had to sketchily use one of the drive PWM splitters on the intake, which meant we had to use all four
	 * for the drive. I know, I know, there are better ways, but I was coding fast and just wanted a working bot.
	 * -Alex
	 */
	Spark frontLeft, frontRight, backLeft, backRight;

public:
	TankDriveTrain(MotorPin frontLeftPin, MotorPin frontRightPin, MotorPin backLeftPin, MotorPin backRightPin);
	void InitDefaultCommand();
	void Stop();
	void Drive(SDriveData driveData);
};

#endif  // TankDrive_H


#ifndef MecanumDrive_H
#define MecanumDrive_H

#include <Commands/Subsystem.h>
#include "IDriveTrain.h"
#include "../PinEnums.h"
#include <Spark.h>

class MecanumDriveTrain : public IDriveTrain {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	Spark fr;
	Spark fl;
	Spark br;
	Spark bl;

public:
	MecanumDriveTrain(MotorPin frontLeftPin, MotorPin frontRightPin, MotorPin backLeftPin, MotorPin backRightPin);
	void InitDefaultCommand() override;
	void Stop();
	void Drive(SDriveData driveData);
};

#endif  // MecanumDrive_H

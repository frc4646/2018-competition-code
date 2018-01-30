#include "IDriveTrain.h"
#include <Spark.h>
#include <Subsystems/Drivetrain/TankDriveTrain.h>
#include "../../PinEnums.h"
#include "Commands/HandleTankDrive.h"

TankDriveTrain::TankDriveTrain(MotorPin leftPin, MotorPin rightPin) :
	IDriveTrain("TankDrive"),
	left(leftPin),
	right(rightPin) {

}

void TankDriveTrain::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
	SetDefaultCommand(new HandleTankDrive());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void TankDriveTrain::Stop() {
	left.Set(0);
	right.Set(0);
}

void TankDriveTrain::DoDrive(SDriveData driveData) {
	left.Set(driveData.lTank);
	right.Set(driveData.rTank);
}

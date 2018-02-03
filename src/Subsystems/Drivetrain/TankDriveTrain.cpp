#include "IDriveTrain.h"
#include <Spark.h>
#include <Subsystems/Drivetrain/TankDriveTrain.h>
#include <PinEnums.h>
#include <Commands/HandleTankDrive.h>

TankDriveTrain::TankDriveTrain(MotorPin frontLeftPin, MotorPin frontRightPin, MotorPin backLeftPin, MotorPin backRightPin) :
	IDriveTrain("TankDrive"),
	frontLeft(frontLeftPin),
	frontRight(backRightPin),
	backLeft(backLeftPin),
	backRight(backRightPin){

}

void TankDriveTrain::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
	SetDefaultCommand(new HandleTankDrive());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void TankDriveTrain::Stop() {
	frontLeft.Set(0);
	frontRight.Set(0);
	backLeft.Set(0);
	backRight.Set(0);
}

void TankDriveTrain::Drive(SDriveData driveData) {
	frontLeft.Set(driveData.lTank);
	frontRight.Set(driveData.rTank);
	backLeft.Set(driveData.lTank);
	backRight.Set(driveData.rTank);
}


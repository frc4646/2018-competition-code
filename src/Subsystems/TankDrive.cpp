#include "TankDrive.h"
#include "IDriveTrain.h"
#include <Spark.h>
#include "../PinEnums.h"
#include "../RobotMap.h"
#include "Commands/HandleTankDrive.h"

TankDrive::TankDrive(MotorPin leftPin, MotorPin rightPin) :
	IDriveTrain("TankDrive"),
	left(leftPin),
	right(rightPin) {

}

void TankDrive::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
	SetDefaultCommand(new HandleTankDrive());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void TankDrive::Stop() {
	left.Set(0);
	right.Set(0);
}

void TankDrive::Drive(SDriveData driveData) {
	left.Set(driveData.lTank);
	right.Set(driveData.rTank);
}

#include <Commands/HandleMecanumDrive.h>
#include <Subsystems/MecanumDriveTrain.h>
#include "../PinEnums.h"
#include "IDriveTrain.h"
#include <cmath>
#define PI 3.141592

MecanumDriveTrain::MecanumDriveTrain(MotorPin frontLeftPin, MotorPin frontRightPin, MotorPin backLeftPin, MotorPin backRightPin) :
	IDriveTrain("MecanumDrive"),
	fl(frontLeftPin),
	fr(frontRightPin),
	bl(backLeftPin),
	br(backRightPin) {

}

void MecanumDriveTrain::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
	SetDefaultCommand(new HandleDrive());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void MecanumDriveTrain::Stop() {
	fl.Set(0);
	fr.Set(0);
	bl.Set(0);
	br.Set(0);
}

void MecanumDriveTrain::Drive(SDriveData driveData) {
	double r = hypot(driveData.cartX, driveData.cartY);
	double theta = atan2(driveData.cartY, driveData.cartX);
	fl.Set(r * sin(theta + (PI / 4)) + driveData.cartR);
	fr.Set(r * cos(theta + (PI / 4)) - driveData.cartR);
	bl.Set(r * cos(theta + (PI / 4)) + driveData.cartR);
	br.Set(r * sin(theta + (PI / 4)) - driveData.cartR);
}

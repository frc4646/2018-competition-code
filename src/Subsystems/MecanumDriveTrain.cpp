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
	fl.SetSafetyEnabled(false);
	fr.SetSafetyEnabled(false);
	bl.SetSafetyEnabled(false);
	br.SetSafetyEnabled(false);
	fl.SetInverted(true);
	bl.SetInverted(true);
}

void MecanumDriveTrain::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
	SetDefaultCommand(new HandleDrive());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void MecanumDriveTrain::Stop() {
	fl.Set(0.0);
	fr.Set(0.0);
	bl.Set(0.0);
	br.Set(0.0);
}

void MecanumDriveTrain::Drive(SDriveData driveData) {
	frc::SmartDashboard::PutNumber("Test 1", 5);
	double r = hypot(driveData.cartX, driveData.cartY);
	double theta = atan2(driveData.cartY, driveData.cartX) + (0.5 * PI);
	fl.Set(r * sin(theta + (PI / 4)) + driveData.cartR);
	fr.Set(r * cos(theta + (PI / 4)) - driveData.cartR);
	bl.Set(r * cos(theta + (PI / 4)) + driveData.cartR);
	br.Set(r * sin(theta + (PI / 4)) - driveData.cartR);
}

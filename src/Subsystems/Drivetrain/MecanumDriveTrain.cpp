#include <Commands/HandleMecanumDrive.h>
#include "MecanumDriveTrain.h"
#include <PinEnums.h>
#include "IDriveTrain.h"
#include <cmath>
#include <LOOP/PID.h>
#define PI 3.141592

MecanumDriveTrain::MecanumDriveTrain(MotorPin frontLeftPin, MotorPin frontRightPin, MotorPin backLeftPin, MotorPin backRightPin) :
	IDriveTrain("MecanumDrive"),
	fl(frontLeftPin),
	fr(frontRightPin),
	bl(backLeftPin),
	br(backRightPin),
	doTracking(true),
	trackingAngle(0),
	pid(1.0,2.0,3.0) {
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
	SetDefaultCommand(new HandleMecanumDrive());
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
	double r = hypot(driveData.cartX, driveData.cartY);
	double theta = atan2(driveData.cartY, driveData.cartX) + (0.5 * PI);
	//frc::SmartDashboard::PutNumber("Heading", fmod(theta, 2.0 * PI));
	fl.Set(r * sin(theta + (PI / 4)) + driveData.cartR);
	fr.Set(r * cos(theta + (PI / 4)) - driveData.cartR);
	bl.Set(r * cos(theta + (PI / 4)) + driveData.cartR);
	br.Set(r * sin(theta + (PI / 4)) - driveData.cartR);
}

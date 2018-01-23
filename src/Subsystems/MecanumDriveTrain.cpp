#include <Commands/HandleMecanumDrive.h>
#include <Subsystems/MecanumDriveTrain.h>
#include "../PinEnums.h"
#include <cmath>
#define PI 3.141592

using namespace loop;

MecanumDriveTrain::MecanumDriveTrain(MotorPin frontLeftPin, MotorPin frontRightPin, MotorPin backLeftPin, MotorPin backRightPin) :
	IDriveTrain("MecanumDrive"),
	fl(frontLeftPin),
	fr(frontRightPin),
	bl(backLeftPin),
	br(backRightPin),
	trackingAngle(0),
	doTracking(false),
	pid(frc::Preferences::GetInstance()->GetDouble("kP", 0.1), frc::Preferences::GetInstance()->GetDouble("kI", 0), 0) {
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
	fl.SetSafetyEnabled(true);
	fr.SetSafetyEnabled(true);
	bl.SetSafetyEnabled(true);
	br.SetSafetyEnabled(true);
}

void MecanumDriveTrain::Drive(SDriveData driveData) {
	pid.SetInput(gyro.GetAngle());
	double r = hypot(driveData.cartX, driveData.cartY);
	double theta = atan2(driveData.cartY, driveData.cartX) + (0.5 * PI);
	//frc::SmartDashboard::PutNumber("Heading", fmod(theta, 2.0 * PI));
	if (doTracking) {
		double rot = pid.GetOutput();
		fl.Set(r * sin(theta + (PI / 4)) + rot);
		fr.Set(r * cos(theta + (PI / 4)) - rot);
		bl.Set(r * cos(theta + (PI / 4)) + rot);
		br.Set(r * sin(theta + (PI / 4)) - rot);
	} else {
		fl.Set(r * sin(theta + (PI / 4)) + driveData.cartR);
		fr.Set(r * cos(theta + (PI / 4)) - driveData.cartR);
		bl.Set(r * cos(theta + (PI / 4)) + driveData.cartR);
		br.Set(r * sin(theta + (PI / 4)) - driveData.cartR);
	}
}

void MecanumDriveTrain::EnableTracking(bool enable) {
	doTracking = enable;
}

bool MecanumDriveTrain::TrackingEnabled() {
	return doTracking;
}

void MecanumDriveTrain::SetAngleTrackingTarget(double angle) {
	pid.SetSetpoint(angle);
}

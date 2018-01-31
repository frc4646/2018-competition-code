#include "IDriveTrain.h"
#include <Commands/Subsystem.h>
#include <ADXRS450_Gyro.h>
#include "PID.h"

using namespace loop;

IDriveTrain::IDriveTrain(std::string name) : Subsystem(name), gyro(), trackingPid(0.045, 0, 0) {
	gyro.Calibrate();
	trackingPid.BindInput(GetAngle);
}

void IDriveTrain::Drive(SDriveData driveData) {
	if (track) {
		driveData.cartR = trackingPid.GetOutput();
	}
	DoDrive(driveData);
}

double IDriveTrain::GetAngle() {
	return gyro.GetAngle();
}

void IDriveTrain::TrackAngle(double angle) {
	trackingPid.SetInput(GetAngle());
	trackingPid.SetSetpoint(angle);
}

void IDriveTrain::EnableTracking(bool enabled) {
	track = enabled;
}

bool IDriveTrain::BusyTracking() {
	return track && (GetAngle() < trackingPid.GetSetpoint() - 2 || GetAngle() > trackingPid.GetSetpoint() + 2);
}

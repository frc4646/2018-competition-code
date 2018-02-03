#include "RotateToPoint.h"
#include "LOOP/IDriveTrain.h"

using namespace loop;

RotateToPoint::RotateToPoint(double angle) : target(angle) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(drivetrain.get());
}

// Called just before this Command runs the first time
void RotateToPoint::Initialize() {
	drivetrain->EnableTracking(true);
	drivetrain->SetAngleTrackingTarget(target);
}

// Called repeatedly when this Command is scheduled to run
void RotateToPoint::Execute() {
	SDriveData data;
	drivetrain->Drive(data);
}

// Make this return true when this Command no longer needs to run execute()
bool RotateToPoint::IsFinished() {
	return drivetrain->AngleTrackingTargetMet();
}

// Called once after isFinished returns true
void RotateToPoint::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void RotateToPoint::Interrupted() {

}


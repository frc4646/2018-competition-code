<<<<<<< HEAD
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
	drivetrain->TrackAngle(target);
}

// Called repeatedly when this Command is scheduled to run
void RotateToPoint::Execute() {
	SDriveData data;
	drivetrain->Drive(data);
}

// Make this return true when this Command no longer needs to run execute()
bool RotateToPoint::IsFinished() {
	return !drivetrain->BusyTracking();
}

// Called once after isFinished returns true
void RotateToPoint::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void RotateToPoint::Interrupted() {

}
=======
#include "RotateToPoint.h"

RotateToPoint::RotateToPoint() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void RotateToPoint::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void RotateToPoint::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool RotateToPoint::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void RotateToPoint::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void RotateToPoint::Interrupted() {

}
>>>>>>> 7c4ef7586961181d848fb171a63752b73ecdac32

#include "DriveToPoint.h"

DriveToPoint::DriveToPoint(double distance) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void DriveToPoint::Initialize() {
 //TODO
}

// Called repeatedly when this Command is scheduled to run
void DriveToPoint::Execute() {

	 //TODO MLL - Use Drive + Encoders to figure out how far you have gone. May
	// need more setters/getters in Drive subsystem
}

// Make this return true when this Command no longer needs to run execute()
bool DriveToPoint::IsFinished() {
	 //TODO
	return false;
}

// Called once after isFinished returns true
void DriveToPoint::End() {
	 //TODO

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveToPoint::Interrupted() {
	End();
}

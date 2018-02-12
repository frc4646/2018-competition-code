#include "StrafeToPoint.h"

StrafeToPoint::StrafeToPoint(double distance) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	//TODO
}

// Called just before this Command runs the first time
void StrafeToPoint::Initialize() {
	//TODO

}

// Called repeatedly when this Command is scheduled to run
void StrafeToPoint::Execute() {
	//TODO MLL - May need to add more setters/getters to drive

}

// Make this return true when this Command no longer needs to run execute()
bool StrafeToPoint::IsFinished() {
	return false;
	//TODO
}

// Called once after isFinished returns true
void StrafeToPoint::End() {
	//TODO
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void StrafeToPoint::Interrupted() {
	End();
}

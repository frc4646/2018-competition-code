#include "HoldLift.h"

HoldLift::HoldLift() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(lift.get());
}

// Called just before this Command runs the first time
void HoldLift::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void HoldLift::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool HoldLift::IsFinished() {
	return false;
	//This should probably end when we see joystck moton
}

// Called once after isFinished returns true
void HoldLift::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void HoldLift::Interrupted() {

}

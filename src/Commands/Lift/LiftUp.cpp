#include "LiftUp.h"
#include "Config.h"

LiftUp::LiftUp() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(lift.get());
}

// Called just before this Command runs the first time
void LiftUp::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void LiftUp::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool LiftUp::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void LiftUp::End() {
	lift->StopLift();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void LiftUp::Interrupted() {
	End();
}

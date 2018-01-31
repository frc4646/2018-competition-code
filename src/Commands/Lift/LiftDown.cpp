#include "LiftDown.h"
#include "Config.h"

LiftDown::LiftDown() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(lift.get());
}

// Called just before this Command runs the first time
void LiftDown::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void LiftDown::Execute() {
	lift->SetLiftPower(-liftMovementFactor);
}

// Make this return true when this Command no longer needs to run execute()
bool LiftDown::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void LiftDown::End() {
	lift->StopLift();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void LiftDown::Interrupted() {
	End();
}

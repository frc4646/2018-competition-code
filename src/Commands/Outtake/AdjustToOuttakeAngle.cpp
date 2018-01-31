#include "AdjustToOuttakeAngle.h"

AdjustToOuttakeAngle::AdjustToOuttakeAngle() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(intake.get());
}

// Called just before this Command runs the first time
void AdjustToOuttakeAngle::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void AdjustToOuttakeAngle::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool AdjustToOuttakeAngle::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void AdjustToOuttakeAngle::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AdjustToOuttakeAngle::Interrupted() {

}


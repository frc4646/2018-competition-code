#include "AdjustToIntakeAngle.h"

AdjustToIntakeAngle::AdjustToIntakeAngle() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(intake.get());
}

// Called just before this Command runs the first time
void AdjustToIntakeAngle::Initialize() {
	intake->SetIntakeAngle(-15);
}

// Called repeatedly when this Command is scheduled to run
void AdjustToIntakeAngle::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool AdjustToIntakeAngle::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void AdjustToIntakeAngle::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AdjustToIntakeAngle::Interrupted() {

}

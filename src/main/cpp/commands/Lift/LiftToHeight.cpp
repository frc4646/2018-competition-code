#include <Commands/Lift/LiftToHeight.h>

LiftToHeight::LiftToHeight(double height) : CommandBase("LiftToHeight") {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(lift.get());
}

// Called just before this Command runs the first time
void LiftToHeight::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void LiftToHeight::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool LiftToHeight::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void LiftToHeight::End() {
	lift->StopLift();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void LiftToHeight::Interrupted() {
	End();
}

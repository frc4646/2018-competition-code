#include <Commands/Intake/IntakeTiltSet.h>

IntakeTiltSet::IntakeTiltSet() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(intake.get());
}

// Called just before this Command runs the first time
void IntakeTiltSet::Initialize() {
	intake->SetIntakePower(0);
}

// Called repeatedly when this Command is scheduled to run
void IntakeTiltSet::Execute() {
	if (oi->GetMechanismTrigger()){
		intake->SetIntakePower(oi->GetMechanismY());
	}
	else{
		intake->SetIntakePower(0);
	}
}

// Make this return true when this Command no longer needs to run execute()
bool IntakeTiltSet::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void IntakeTiltSet::End() {
	intake->SetIntakePower(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void IntakeTiltSet::Interrupted() {

}

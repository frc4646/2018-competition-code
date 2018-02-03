#include <Commands/Intake/IntakePowerSet.h>

IntakePowerSet::IntakePowerSet() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(intake.get());
}

// Called just before this Command runs the first time
void IntakePowerSet::Initialize() {
	intake->SetIntakePower(0);
}

// Called repeatedly when this Command is scheduled to run
void IntakePowerSet::Execute() {
	if (oi->GetMechanismTrigger()){
		intake->SetIntakePower(oi->GetMechanismY());
	}
	else{
		intake->SetIntakePower(0);
	}
}

// Make this return true when this Command no longer needs to run execute()
bool IntakePowerSet::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void IntakePowerSet::End() {
	intake->SetIntakePower(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void IntakePowerSet::Interrupted() {

}

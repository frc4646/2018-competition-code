#include "IntakeMotorSet.h"

IntakeMotorSet::IntakeMotorSet() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(intake.get());
}

// Called just before this Command runs the first time
void IntakeMotorSet::Initialize() {
	intake->SetIntakePower(0);
}

// Called repeatedly when this Command is scheduled to run
void IntakeMotorSet::Execute() {
	// If trigger on mechanism joystick is being pressed...
	if (!oi->GetMechanismTrigger()){
		// Set intake power to whatever the mechanism joysticks Y value is at, times -1 because the joystick is reversed.
		intake->SetIntakePower((oi->GetMechanismY()*-1));
	}
	// If not...
	else{
		// Set intake power to zero.
		intake->SetIntakePower(0);
	}
}

// Make this return true when this Command no longer needs to run execute()
bool IntakeMotorSet::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void IntakeMotorSet::End() {
	intake->SetIntakePower(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void IntakeMotorSet::Interrupted() {

}

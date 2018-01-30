#include "IntakePowerCube.h"

IntakePowerCube::IntakePowerCube() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(intake.get());
}

// Called just before this Command runs the first time
void IntakePowerCube::Initialize() {
	intake->SetIntakePower(1);
}

// Called repeatedly when this Command is scheduled to run
void IntakePowerCube::Execute() {
}

// Make this return true when this Command no longer needs to run execute()
bool IntakePowerCube::IsFinished() {
	return intake->HasPowerCube();
}

// Called once after isFinished returns true
void IntakePowerCube::End() {
	intake->SetIntakePower(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void IntakePowerCube::Interrupted() {
	End();
}

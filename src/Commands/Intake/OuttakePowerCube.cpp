
#include "OuttakePowerCube.h"

OuttakePowerCube::OuttakePowerCube() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(intake.get());
}

// Called just before this Command runs the first time
void OuttakePowerCube::Initialize() {
	intake->SetIntakePower(-1);
}

// Called repeatedly when this Command is scheduled to run
void OuttakePowerCube::Execute() {
	intake->SetIntakePower(-1);
}

// Make this return true when this Command no longer needs to run execute()
bool OuttakePowerCube::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void OuttakePowerCube::End() {
	intake->SetIntakePower(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void OuttakePowerCube::Interrupted() {
	End();
}

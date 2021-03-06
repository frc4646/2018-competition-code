
#include "OuttakePowerCube.h"

OuttakePowerCube::OuttakePowerCube() :
	timer() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(intake.get());
}

// Called just before this Command runs the first time
void OuttakePowerCube::Initialize() {
	timer.Reset();
	timer.Start();
	intake->SetIntakePower(-frc::Preferences::GetInstance()->GetDouble("outtake-power", 0.5));
}

// Called repeatedly when this Command is scheduled to run
void OuttakePowerCube::Execute() {
	intake->SetIntakePower(-frc::Preferences::GetInstance()->GetDouble("outtake-power", 0.5));
}

// Make this return true when this Command no longer needs to run execute()
bool OuttakePowerCube::IsFinished() {
	return timer.Get() > 0.5;
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

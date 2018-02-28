#include "ResetDrivetrainEncoders.h"
#include "Subsystems/Drivetrain/MecanumDriveTrain.h"

ResetDrivetrainEncoders::ResetDrivetrainEncoders() : CommandBase("ResetDrivetrainEncoders") {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(drivetrain.get());
}

// Called just before this Command runs the first time
void ResetDrivetrainEncoders::Initialize() {
	drivetrain->ResetEncoders();
}

// Called repeatedly when this Command is scheduled to run
void ResetDrivetrainEncoders::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool ResetDrivetrainEncoders::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void ResetDrivetrainEncoders::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ResetDrivetrainEncoders::Interrupted() {

}

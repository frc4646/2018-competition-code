#include "HandleMecanumDrive.h"

HandleMecanumDrive::HandleMecanumDrive() : CommandBase("HandleDrive") {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(drivetrain.get());
}

// Called just before this Command runs the first time
void HandleMecanumDrive::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void HandleMecanumDrive::Execute() {
	SDriveData driveData;
	driveData.cartX = oi->GetMechanismX();
	driveData.cartY = oi->GetMechanismY();
	driveData.cartR = oi->GetLeftJoystickX();
	drivetrain->Drive(driveData);
}

// Make this return true when this Command no longer needs to run execute()
bool HandleMecanumDrive::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void HandleMecanumDrive::End() {
	drivetrain->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void HandleMecanumDrive::Interrupted() {
	End();
}

#include "HandleMecanumDrive.h"

HandleDrive::HandleDrive() : CommandBase("HandleDrive") {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(drivetrain.get());
}

// Called just before this Command runs the first time
void HandleDrive::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void HandleDrive::Execute() {
	SDriveData driveData;
	driveData.cartX = oi->GetRightJoystickX();
	driveData.cartY = oi->GetRightJoystickY();
	driveData.cartR = oi->GetLeftJoystickX();
	drivetrain->Drive(driveData);
}

// Make this return true when this Command no longer needs to run execute()
bool HandleDrive::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void HandleDrive::End() {
	drivetrain->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void HandleDrive::Interrupted() {
	End();
}

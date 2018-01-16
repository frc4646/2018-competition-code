#include "HandleTankDrive.h"

HandleTankDrive::HandleTankDrive() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(drivetrain.get());
}

// Called just before this Command runs the first time
void HandleTankDrive::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void HandleTankDrive::Execute() {
	SDriveData driveData;
	driveData.lTank = oi->GetLeftJoystickY();
	driveData.rTank = oi->GetRightJoystickY();
	drivetrain->Drive(driveData);
}

// Make this return true when this Command no longer needs to run execute()
bool HandleTankDrive::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void HandleTankDrive::End() {
	drivetrain->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void HandleTankDrive::Interrupted() {
	End();
}

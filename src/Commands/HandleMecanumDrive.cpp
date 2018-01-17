#include "HandleMecanumDrive.h"

using namespace loop;

float HandleMecanumDrive::target = 0;
bool HandleMecanumDrive::trackTarget = false;

HandleMecanumDrive::HandleMecanumDrive() : CommandBase("HandleDrive") {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires((frc::Subsystem*) drivetrain.get());
	target = 0;
	trackTarget = false;
}

// Called just before this Command runs the first time
void HandleMecanumDrive::Initialize() {
	frc::SmartDashboard::PutNumber("P", 0);
	frc::SmartDashboard::PutNumber("IC", 0);
}

// Called repeatedly when this Command is scheduled to run

void HandleMecanumDrive::Execute() {
	SDriveData driveData;
	driveData.cartX = oi->GetMechanismX();
	driveData.cartY = oi->GetMechanismY();
	driveData.cartR = oi->GetLeftJoystickX();

	//tar = frc::SmartDashboard::GetNumber("Target", 0);

	frc::SmartDashboard::PutNumber("Gyro heading", drivetrain->GetAngle());
	if (trackTarget) {
		driveData.cartR = std::max(std::min(frc::SmartDashboard::GetNumber("P", 0) * (drivetrain->GetAngle() - target), frc::SmartDashboard::GetNumber("IC", 0)), -frc::SmartDashboard::GetNumber("IC", 0));
		frc::SmartDashboard::PutNumber("CartR", driveData.cartR);
		frc::SmartDashboard::PutNumber("Err", (drivetrain->GetAngle() - target));
	}

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

/*void HandleMecanumDrive::ShouldRunTargeting(bool enabled) {
	HandleMecanumDrive::tarHeadingMode = enabled;
}

bool HandleMecanumDrive::IsTargeting() {
	return HandleMecanumDrive::tarHeadingMode;
}

void HandleMecanumDrive::SetTarget(float target) {
	HandleMecanumDrive::tar = target;
}*/

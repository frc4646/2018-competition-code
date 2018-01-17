#include "HandleMecanumDrive.h"

HandleMecanumDrive::HandleMecanumDrive() : CommandBase("HandleDrive"), tarHeadingMode(true), tar(0), gyro() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(drivetrain.get());
	gyro.Calibrate();
}

// Called just before this Command runs the first time
void HandleMecanumDrive::Initialize() {
	gyro.Reset();
	frc::SmartDashboard::PutNumber("P", 0);
	frc::SmartDashboard::PutNumber("IC", 0);
}

// Called repeatedly when this Command is scheduled to run

void HandleMecanumDrive::Execute() {
	SDriveData driveData;
	driveData.cartX = oi->GetMechanismX();
	driveData.cartY = oi->GetMechanismY();
	driveData.cartR = oi->GetLeftJoystickX();

	tarHeadingMode = frc::SmartDashboard::GetBoolean("Heading Targeting", false);
	tar = frc::SmartDashboard::GetNumber("Target", 0);

	frc::SmartDashboard::PutNumber("Gyro heading", gyro.GetAngle());
	if (tarHeadingMode) {
		double r = std::max(std::min(frc::SmartDashboard::GetNumber("P", 0) * (gyro.GetAngle() - tar), frc::SmartDashboard::GetNumber("IC", 0)), -frc::SmartDashboard::GetNumber("IC", 0));
		double sig = (r < 0.0) ? -1.0 : 1.0;
		//double rr = sig * ((std::fabs(r))*(std::fabs(r)));
		driveData.cartR = r; //rr
		frc::SmartDashboard::PutNumber("CartR", driveData.cartR);
		frc::SmartDashboard::PutNumber("Err", (gyro.GetAngle() - tar));
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

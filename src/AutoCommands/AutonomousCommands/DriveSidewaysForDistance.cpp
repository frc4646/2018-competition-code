#include "DriveSidewaysForDistance.h"

DriveSidewaysForDistance::DriveSidewaysForDistance(double distance) : CommandBase("DSFD"),
	dist(distance) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(drivetrain.get());
}

// Called just before this Command runs the first time
void DriveSidewaysForDistance::Initialize() {
	drivetrain->ResetEncoders();
	drivetrain->ResetEncoderPIDs();

	double sign = 1;
	if (frc::DriverStation::GetInstance().GetGameSpecificMessage()[0] == 'L') {
		sign = -1;
	}

	// stopship
	drivetrain->SetEncoderTarget(MecanumDriveTrain::EncoderIndex::FRONT_LEFT, (sign * dist) / -0.38);
	drivetrain->SetEncoderTarget(MecanumDriveTrain::EncoderIndex::FRONT_RIGHT, (sign * dist) / 0.2683);
	drivetrain->SetEncoderTarget(MecanumDriveTrain::EncoderIndex::BACK_LEFT, (sign * dist) / 0.262);
	drivetrain->SetEncoderTarget(MecanumDriveTrain::EncoderIndex::BACK_RIGHT, (sign * dist) / -0.4048);
	drivetrain->EnableRunToPosition(true);
	drivetrain->EnableTracking(true);
}

// Called repeatedly when this Command is scheduled to run
void DriveSidewaysForDistance::Execute() {
	loop::SDriveData data;
	drivetrain->Drive(data);
}

// Make this return true when this Command no longer needs to run execute()
bool DriveSidewaysForDistance::IsFinished() {
	return (drivetrain->EncodersAtTarget((MecanumDriveTrain::EncoderIndex) (
				MecanumDriveTrain::EncoderIndex::FRONT_RIGHT |
				MecanumDriveTrain::EncoderIndex::BACK_LEFT |
				MecanumDriveTrain::EncoderIndex::BACK_RIGHT
	)));
}

// Called once after isFinished returns true
void DriveSidewaysForDistance::End() {
	drivetrain->EnableRunToPosition(false);
	drivetrain->EnableTracking(false);
	drivetrain->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveSidewaysForDistance::Interrupted() {
	End();
}

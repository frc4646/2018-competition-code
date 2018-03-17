#include "DriveSidewaysForDistance.h"
#include <LOOP/Utils.h>
#include <Config.h>

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
	/*drivetrain->SetEncoderTarget(MecanumDriveTrain::EncoderIndex::FRONT_LEFT, (sign * dist) * -0.38);
	drivetrain->SetEncoderTarget(MecanumDriveTrain::EncoderIndex::FRONT_RIGHT, (sign * dist) / 0.2683);
	drivetrain->SetEncoderTarget(MecanumDriveTrain::EncoderIndex::BACK_LEFT, (sign * dist) / 0.262);
	drivetrain->SetEncoderTarget(MecanumDriveTrain::EncoderIndex::BACK_RIGHT, (sign * dist) / -0.4048);
	drivetrain->EnableRunToPosition(true);*/
	drivetrain->EnableAngleHold(true);
	drivetrain->SetAngleTrackingTarget(0);
	drivetrain->EnableTracking(true);
}

// Called repeatedly when this Command is scheduled to run
void DriveSidewaysForDistance::Execute() {
	loop::SDriveData data;
	data.cartX = (dist > 0) ? 0.75 : -0.75;
	data.cartR = 2;
	drivetrain->Drive(data);
}

// Make this return true when this Command no longer needs to run execute()
bool DriveSidewaysForDistance::IsFinished() {
	/*return (drivetrain->EncodersAtTarget((MecanumDriveTrain::EncoderIndex) (
				MecanumDriveTrain::EncoderIndex::FRONT_RIGHT |
				MecanumDriveTrain::EncoderIndex::BACK_LEFT |
				MecanumDriveTrain::EncoderIndex::BACK_RIGHT
	)));*/
	bool ret = false;
	ret |= loop::withinRange(drivetrain->GetEncoderRaw(MecanumDriveTrain::EncoderIndex::FRONT_RIGHT), (Config::strafeFRRatio * dist) - 600.0, (Config::strafeFRRatio * dist));
	ret |= loop::withinRange(drivetrain->GetEncoderRaw(MecanumDriveTrain::EncoderIndex::BACK_LEFT), (Config::strafeBLRatio * dist) - 600.0, (Config::strafeBLRatio * dist));
	ret |= loop::withinRange(drivetrain->GetEncoderRaw(MecanumDriveTrain::EncoderIndex::BACK_RIGHT), (Config::strafeBRRatio * dist) - 600.0, (Config::strafeBRRatio * dist));
	//ret |= loop::withinRange(drivetrain->GetEncoderRaw(MecanumDriveTrain::EncoderIndex::FRONT_LEFT), (Config::strafeFLRatio * dist) - 600.0, (Config::strafeFLRatio * dist));
	return ret;
}

// Called once after isFinished returns true
void DriveSidewaysForDistance::End() {
	//drivetrain->EnableRunToPosition(false);
	drivetrain->EnableTracking(false);
	drivetrain->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveSidewaysForDistance::Interrupted() {
	End();
}

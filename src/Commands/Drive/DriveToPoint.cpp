#include "DriveToPoint.h"
#include <Encoder.h>
#include <cmath>
#include <Config.h>
#include <Subsystems/Drivetrain/MecanumDriveTrain.h>
#include <LOOP/Utils.h>
#ifndef PI
#define PI 3.1415926
#endif

DriveToPoint::DriveToPoint(double x, double y) : CommandBase("DriveToPoint"),
	tx(x),
	ty(y),
	theta(std::atan2(ty, tx) - (0.5 * PI)),
	dist(std::hypot(tx, ty)),
	state(State::TURNING_TO_THETA) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(drivetrain.get());
}

// Called just before this Command runs the first time
void DriveToPoint::Initialize() {
	// Clean up any mess previous commands may have left
	drivetrain->ResetEncoders();
	drivetrain->ResetEncoderPIDs();
	drivetrain->EnableRunToPosition(false);

	drivetrain->SetAngleTrackingTarget(theta);
	drivetrain->EnableTracking(true);
}

// Called repeatedly when this Command is scheduled to run
void DriveToPoint::Execute() {
	if (state == State::TURNING_TO_THETA) {
		if (drivetrain->AngleTrackingTargetMet()) {
			state = State::DRIVING_TO_DIST;
			drivetrain->ResetEncoders();
			drivetrain->ResetEncoderPIDs();
			//drivetrain->SetEncoderTarget(MecanumDriveTrain::EncoderIndex::FRONT_LEFT, dist);
			drivetrain->SetEncoderTarget(MecanumDriveTrain::EncoderIndex::FRONT_RIGHT, dist);
			drivetrain->SetEncoderTarget(MecanumDriveTrain::EncoderIndex::BACK_LEFT, dist);
			drivetrain->SetEncoderTarget(MecanumDriveTrain::EncoderIndex::BACK_RIGHT, dist);
			drivetrain->EnableRunToPosition(true);
		}
	}
	loop::SDriveData driveData;
	driveData.cartX = 0;
	driveData.cartY = 0;
	driveData.cartR = 0;
	drivetrain->Drive(driveData);
}

// Make this return true when this Command no longer needs to run execute()
bool DriveToPoint::IsFinished() {
	return (state == State::DRIVING_TO_DIST) && drivetrain->EncodersAtTarget((MecanumDriveTrain::EncoderIndex) (
			MecanumDriveTrain::EncoderIndex::FRONT_RIGHT |
			MecanumDriveTrain::EncoderIndex::BACK_LEFT |
			MecanumDriveTrain::EncoderIndex::BACK_RIGHT
	));
}

// Called once after isFinished returns true
void DriveToPoint::End() {
	 // Clean up after ourselves
	drivetrain->EnableRunToPosition(false);
	drivetrain->EnableTracking(false);
	drivetrain->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveToPoint::Interrupted() {
	End();
}

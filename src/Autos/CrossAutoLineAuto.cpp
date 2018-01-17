#include "CrossAutoLineAuto.h"

using namespace loop;

CrossAutoLineAuto::CrossAutoLineAuto() :
	CommandBase("CrossAutoLineAuto"),
	driveTime(frc::Preferences::GetInstance()->GetDouble("CALA-driveTime", 0)) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(drivetrain.get());
}

// Called just before this Command runs the first time
void CrossAutoLineAuto::Initialize() {
	timer.Reset();
	timer.Start();
	SDriveData driveData;
	driveData.cartX = 0;
	driveData.cartY = 1;
	driveData.cartR = 0;
	drivetrain->Drive(driveData);
}

// Called repeatedly when this Command is scheduled to run
void CrossAutoLineAuto::Execute() {
	frc::SmartDashboard::PutNumber("Time elapsed", timer.Get());
	frc::SmartDashboard::PutNumber("Drive time", driveTime);
}

// Make this return true when this Command no longer needs to run execute()
bool CrossAutoLineAuto::IsFinished() {
	return timer.Get() >= driveTime;
}

// Called once after isFinished returns true
void CrossAutoLineAuto::End() {
	drivetrain->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CrossAutoLineAuto::Interrupted() {
	End();
}

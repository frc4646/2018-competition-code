#include "DriveForwardForTime.h"
#include "LOOP/IDriveTrain.h"

DriveForwardForTime::DriveForwardForTime(double t) : CommandBase("DFFT"), time(t), timer() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(drivetrain.get());
}

// Called just before this Command runs the first time
void DriveForwardForTime::Initialize() {
	loop::SDriveData data;
	data.cartY = 0.75;
	drivetrain->Drive(data);
	timer.Reset();
	timer.Start();
}

// Called repeatedly when this Command is scheduled to run
void DriveForwardForTime::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool DriveForwardForTime::IsFinished() {
	return timer.Get() >= time;
}

// Called once after isFinished returns true
void DriveForwardForTime::End() {
	drivetrain->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveForwardForTime::Interrupted() {
	End();
}

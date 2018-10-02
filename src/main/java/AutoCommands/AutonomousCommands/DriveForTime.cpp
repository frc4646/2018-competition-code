#include <AutoCommands/AutonomousCommands/DriveForTime.h>
#include "LOOP/IDriveTrain.h"

DriveForTime::DriveForTime(double t, bool back) : CommandBase("DFFT"), time(t), _back(back), timer() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(drivetrain.get());
}

// Called just before this Command runs the first time
void DriveForTime::Initialize() {
	loop::SDriveData data;
	if (!_back){
		data.cartY = 0.75;
	}
	else{
		data.cartY = -0.75;
	}
	drivetrain->Drive(data);
	timer.Reset();
	timer.Start();
}

// Called repeatedly when this Command is scheduled to run
void DriveForTime::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool DriveForTime::IsFinished() {
	return timer.Get() >= time;
}

// Called once after isFinished returns true
void DriveForTime::End() {
	drivetrain->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveForTime::Interrupted() {
	End();
}

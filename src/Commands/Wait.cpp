#include "Wait.h"

Wait::Wait(double time) : CommandBase("Wait"),
	timer(),
	_time(time) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void Wait::Initialize() {
	timer.Reset();
	timer.Start();
}

// Called repeatedly when this Command is scheduled to run
void Wait::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool Wait::IsFinished() {
	return timer.Get() >= _time;
}

// Called once after isFinished returns true
void Wait::End() {
	timer.Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Wait::Interrupted() {
	End();
}

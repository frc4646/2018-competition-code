#include <AutoCommands/AutonomousCommands/Kickstand.h>
#include "CommandBase.h"

Kickstand::Kickstand() : CommandBase("Kickstand"),
	timer() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(lift.get());
}

// Called just before this Command runs the first time
void Kickstand::Initialize() {
	lift->SetLiftPower(0.3);
	timer.Reset();
	timer.Start();
}

// Called repeatedly when this Command is scheduled to run
void Kickstand::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool Kickstand::IsFinished() {
	return timer.Get() > 0.75;
}

// Called once after isFinished returns true
void Kickstand::End() {
	lift->SetLiftPower(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Kickstand::Interrupted() {
	End();
}

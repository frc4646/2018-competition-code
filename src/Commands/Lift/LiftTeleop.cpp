#include <Commands/Lift/LiftTeleop.h>
#include "Config.h"

LiftTeleop::LiftTeleop() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(lift.get());
}

// Called just before this Command runs the first time
void LiftTeleop::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void LiftTeleop::Execute() {

	//Need to consder lift up, lift down, holding the lift in place, and turning on the ratchet to climb
	if (oi->GetMechanism().GetRawButton(1)){
		lift->SetLiftPower(oi->GetMechanismY());
	}
	else {
		lift->SetLiftPower(0.15);
	}

}

// Make this return true when this Command no longer needs to run execute()
bool LiftTeleop::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void LiftTeleop::End() {
	lift->StopLift();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void LiftTeleop::Interrupted() {
	End();
}

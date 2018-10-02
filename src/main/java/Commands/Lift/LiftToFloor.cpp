#include "LiftToFloor.h"
#include <WPILib.h>
#include <Subsystems/Lift/LiftControl.h>

LiftToFloor::LiftToFloor() : CommandBase("LiftToFloor") {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(lift.get());
}

// Called just before this Command runs the first time
void LiftToFloor::Initialize() {
	lift->SetLiftPower(-0.3);
}

// Called repeatedly when this Command is scheduled to run
void LiftToFloor::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool LiftToFloor::IsFinished() {
	return (liftStringPot->GetHeight() <= liftStringPot->GetMinHeight());
}

// Called once after isFinished returns true
void LiftToFloor::End() {
	lift->SetLiftPower(frc::Preferences::GetInstance()->GetDouble("lift-hold-command"));
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void LiftToFloor::Interrupted() {

}

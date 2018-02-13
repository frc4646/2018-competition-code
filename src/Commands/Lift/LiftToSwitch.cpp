#include "LiftToSwitch.h"
#include <WPILib.h>
#include "UltraSonic.h"
#include "Subsystems/Lift/LiftControl.h"
#include <CommandBase.h>

LiftToSwitch::LiftToSwitch() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(lift.get());
	Requires(ultrasonic.get());

	state = 1;
}

// Called just before this Command runs the first time
void LiftToSwitch::Initialize() {
	state = 1;
	lift->LiftToElevation(CommandBase::liftStringPot->GetMaxHeight());
}

// Called repeatedly when this Command is scheduled to run
void LiftToSwitch::Execute() {
	double distanceToSwitch = 500; //in millimeters. distance from the ultrasonic to the scale, horizontally
	double ultraSonicToCube = 2.0; //TODO (also unit) the distance from the ultra sonic to the bottom of block

	//always check if the lift is higher than max height
	if(CommandBase::liftStringPot->GetHeight() >= CommandBase::liftStringPot->GetMaxHeight()) {
		state = 3;
	}

	switch(state){
		case 1:
		{
			//the ultrasonic should already be in front of the switch, so lift up until it can't see it anymore
			if (ultrasonic->GetDistance() <= distanceToSwitch){
				lift->Lift();

			} else
				state = 2;
		}
			break;

		case 2:
		{
			//passed wall, now go a little higher so cube is above the wall
			double currentHeight = CommandBase::liftStringPot->GetHeight();
			double finalHeight = currentHeight + ultraSonicToCube;

			CommandBase::lift->LiftToElevation(finalHeight);

			if ((CommandBase::liftStringPot->GetHeight() + 1) > finalHeight && (CommandBase::liftStringPot->GetHeight() - 1) < finalHeight)
			{
				state = 3;
			}
		}
			break;

		case 3:
		default:
		{
			//stop the lift
			CommandBase::lift->StopLift();
			state = 3;
		}
			break;
	}
}

// Make this return true when this Command no longer needs to run execute()
bool LiftToSwitch::IsFinished() {
	//stop when hit target/final height
	if (state == 3) {
		return true;
	}

	return false;
}

// Called once after isFinished returns true
void LiftToSwitch::End() {
	CommandBase::lift->StopLift();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void LiftToSwitch::Interrupted() {

}

#include "LiftToScale.h"
#include <WPILib.h>
#include "UltraSonic.h"
#include "Subsystems/Lift/LiftControl.h"
#include <CommandBase.h>

LiftToScale::LiftToScale() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(lift.get());
	Requires(ultrasonic.get());

	state = 1;
}

// Called just before this Command runs the first time
void LiftToScale::Initialize() {
	state = 1;
	lift->LiftToElevation(CommandBase::liftStringPot->GetMaxHeight());
}

// Called repeatedly when this Command is scheduled to run
void LiftToScale::Execute() {

	double distanceToScale = 600; //in millimeters. distance from the ultrasonic to the scale, horizontally
	double ultraSonicToCube = 2.0; //TODO (also unit) the distance from the ultra sonic to the bottom of block

	//always check if the lift is higher than max height
	if(CommandBase::liftStringPot->GetHeight() >= CommandBase::liftStringPot->GetMaxHeight()) {
		state = 4;
	}

	switch(state){
		case 1:
		{
			//we are not high enough to the scale, so keep going up
			if (ultrasonic->GetDistance() > distanceToScale || ultrasonic->GetDistance() < 0){
				//run lift up
				lift->Lift();

			} else {
				state = 2;
			}
		}
			break;

		case 2:
		{
			//we've seen the scale, so go higher to pass the border on the scale
			if (ultrasonic->GetDistance() <= distanceToScale) {
				lift->Lift();
			} else {
				state = 3;
			}
		}
			break;

		case 3:
		{
			//passed wall, now go a little higher so cube is above the border of the scale
			double currentHeight = CommandBase::liftStringPot->GetHeight();
			double finalHeight = currentHeight + ultraSonicToCube;

			CommandBase::lift->LiftToElevation(finalHeight);

			//MLL - I think this is really close to what we want to do, but we need to stay in this
			//state until we actually get to the final height. Right now we will just be in here for
			// one time step.
			//1 is delta
			if ((CommandBase::liftStringPot->GetHeight() + 1) > finalHeight && (CommandBase::liftStringPot->GetHeight() - 1) < finalHeight)
			{
				state = 4;
			}

		}
			break;

		case 4:
		default:
		{
			//stop the lift
			CommandBase::lift->StopLift();
			state = 4;
		}
			break;
	}

}

// Make this return true when this Command no longer needs to run execute()
bool LiftToScale::IsFinished() {
	//stop when hit target/final height
	if (state == 4) {
		return true;
	}

	return false;

	//MLL this can be replaced with return (state == 4) if you want, but you also might
	//want to consder ending early f we see joystck motiion
}

// Called once after isFinished returns true
void LiftToScale::End() {
	//TODO we should add somthing here (probably stopping the lift)
	//done 2/12/2018 Stella
	CommandBase::lift->StopLift();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void LiftToScale::Interrupted() {
	End();
}

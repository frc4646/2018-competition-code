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
}

// Called repeatedly when this Command is scheduled to run
void LiftToScale::Execute() {

	double distanceToScale = 600; //unit??
	double liftPower = 1.0; //TO DO change to reasonable number
	double ultraSonicToCube = 2.0; //TO DO (also unit) the distance from the ultra sonic to the bottom of block
	//3. add height from Ultra Sensor to bottom of block

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
				lift->SetLiftPower(liftPower);
			} else {
				state = 2;
			}
		}
			break;

		case 2:
		{
			//we've seen the scale, so go higher to pass the border on the scale
			if (ultrasonic->GetDistance() <= distanceToScale) {
				lift->SetLiftPower(liftPower);
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
			state = 4;
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
	//4. stop when hit target height or reach max height
	if (state == 4) {
		return true; //double check this
	}

	return false;
}

// Called once after isFinished returns true
void LiftToScale::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void LiftToScale::Interrupted() {

}

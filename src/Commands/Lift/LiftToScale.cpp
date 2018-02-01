#include "LiftToScale.h"
#include <WPILib.h>
#include "UltraSonic.h"

LiftToScale::LiftToScale() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(lift.get());
	Requires(ultrasonic.get());
}

// Called just before this Command runs the first time
void LiftToScale::Initialize() {
	state = 1;
}

// Called repeatedly when this Command is scheduled to run
void LiftToScale::Execute() {
	//1. lift up till see scale

	double distanceToScale = 600;
	//lift.GetDistance();
	//2. lift up till can't see scale
	//3. add height from Ultra Sensor to bottom of block

	switch(state){
	case 1:
		if (ultrasonic->GetDistance() > distanceToScale || ultrasonic->GetDistance() < 0){
			//run lift up
		}

		break;

	case 2:

		break;

	case 3:

		break;

	case 4:
	default:

		break;


	}

	//lift->SetLiftPower(); prototype to run lift

}

// Make this return true when this Command no longer needs to run execute()
bool LiftToScale::IsFinished() {
	//4. stop when hit target height or reach max height
	return false;
}

// Called once after isFinished returns true
void LiftToScale::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void LiftToScale::Interrupted() {

}

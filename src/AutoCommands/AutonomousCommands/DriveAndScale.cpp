#include "DriveAndScale.h"

#include <Commands/Drive/ResetGyro.h>
#include <Commands/Lift/LiftToScale.h>
#include <Commands/Lift/LiftToSwitch.h>
#include <Commands/Drive/DriveToPoint.h>
#include <Commands/Drive/RotateToPoint.h>
#include <Commands/Intake/OuttakePowerCube.h>
#include <AutoCommands/AutonomousCommands/DriveForTime.h>
#include <Commands/Lift/LiftToFloor.h>

DriveAndScale::DriveAndScale(bool scale, bool theSwitch, bool right) {
	// Add Commands here:
	// e.g. AddSequential(new Command1());
	//      AddSequential(new Command2());
	// these will run in order.

	// To run multiple commands at the same time,
	// use AddParallel()
	// e.g. AddParallel(new Command1());
	//      AddSequential(new Command2());
	// Command1 and Command2 will run in parallel.

	// A command group will require all of the subsystems that each member
	// would require.
	// e.g. if Command1 requires chassis, and Command2 requires arm,
	// a CommandGroup containing them would require both the chassis and the
	// arm.

	//Reset Gyro
	AddSequential(new ResetGyro());
	//decide if we're doing scale, switch, or neither (sorry Megan!)
	if (scale){
		AddParallel(new LiftToScale());
		AddSequential(new DriveToPoint(0, 280));
		if (!right){
			AddSequential(new RotateToPoint(45));
		}
		else{
			AddSequential(new RotateToPoint(-45));
		}
		AddSequential(new OuttakePowerCube());
		AddSequential(new DriveForTime(0.5, true));
	}
	else if (theSwitch){
		AddParallel(new LiftToSwitch());
		AddSequential(new DriveToPoint(0, 145));
		if (!right){
			AddSequential(new RotateToPoint(80));
		}
		else{
			AddSequential(new RotateToPoint(-90));
		}
		AddSequential(new OuttakePowerCube());
		AddSequential(new DriveForTime(0.5, true));
		AddSequential(new LiftToFloor());
	}
	else{
		AddSequential(new DriveToPoint(0, 126));
	}


	//wheeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee

}

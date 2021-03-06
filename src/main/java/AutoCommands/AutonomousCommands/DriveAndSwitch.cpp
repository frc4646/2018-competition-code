#include "DriveAndSwitch.h"
#include <Commands/CommandGroup.h>
#include <Commands/2018CommandGroups.h>
#include <Commands/Drive/DriveToPoint.h>
#include <AutoCommands/AutonomousCommands/DriveSidewaysForDistance.h>
#include <Commands/Lift/LiftToSwitch.h>
#include <Commands/Intake/OuttakePowerCube.h>
#include <DriverStation.h>
#include <iostream>
#include <Commands/Drive/ResetGyro.h>
#include <Commands/Wait.h>
#include <AutoCommands/AutonomousCommands/DriveForTime.h>
#include <Commands/Lift/LiftToFloor.h>

DriveAndSwitch::DriveAndSwitch(double sideDist) {
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
	// This is in inches
	AddSequential(new ResetGyro());
	AddParallel(new LiftToSwitch());
	AddSequential(new DriveToPoint(0, 36));
	//AddSequential(new Wait(0.5));
	AddSequential(new DriveSidewaysForDistance(sideDist));
	//AddSequential(new Wait(0.5));
	AddSequential(new DriveToPoint(0, 62));
	//AddSequential(new Wait(0.5));
	// *vomits cube*
	AddSequential(new OuttakePowerCube()); //blarghhh
	AddParallel(new LiftToFloor());
	AddSequential(new DriveForTime(0.75, true));
}

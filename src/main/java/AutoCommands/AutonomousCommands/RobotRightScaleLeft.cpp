#include "RobotRightScaleLeft.h"
#include <Commands/Drive/DriveToPoint.h>
#include <Commands/Drive/RotateToPoint.h>

RobotRightScaleLeft::RobotRightScaleLeft() {
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
	AddSequential(new DriveToPoint(0, 0)); //TODO MLL-get correct distance
	AddSequential(new RotateToPoint(90));
	AddSequential(new DriveToPoint(0, 0)); //TODO MLL-get correct distance
	AddSequential(new RotateToPoint(90));
	AddSequential(new LiftToScale());
}

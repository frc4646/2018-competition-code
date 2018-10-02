#ifndef TestDriveToPoint_H
#define TestDriveToPoint_H

#include <Commands/CommandGroup.h>
#include <WPILib.h>

class TestDriveToPoint : public CommandGroup {
public:
	TestDriveToPoint(Vector2d target);
};

#endif  // TestDriveToPoint_H

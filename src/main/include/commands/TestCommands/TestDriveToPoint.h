#ifndef TestDriveToPoint_H
#define TestDriveToPoint_H

#include <frc/Commands/CommandGroup.h>
#include <frc/WPILib.h>

class TestDriveToPoint : public frc::CommandGroup {
public:
	TestDriveToPoint(frc::Vector2d target);
};

#endif  // TestDriveToPoint_H

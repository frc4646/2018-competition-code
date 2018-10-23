#ifndef DriveAndScale_H
#define DriveAndScale_H

#include <Commands/CommandGroup.h>
#include <WPILib.h>

class DriveAndScale : public CommandGroup {
public:
	DriveAndScale(bool scale, bool theSwitch, bool right);
};

#endif  // DriveAndScale_H

#ifndef DriveAndSwitch_H
#define DriveAndSwitch_H

#include <CommandBase.h>

class DriveAndSwitch : public CommandGroup {
public:
	DriveAndSwitch(double sideDist);
};

#endif  // DriveAndSwitch_H

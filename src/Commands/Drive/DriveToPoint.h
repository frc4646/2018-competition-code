#ifndef DriveToPoint_H
#define DriveToPoint_H

#include <CommandBase.h>

class DriveToPoint : public CommandBase {
public:
	DriveToPoint(double distance);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // DriveToPoint_H

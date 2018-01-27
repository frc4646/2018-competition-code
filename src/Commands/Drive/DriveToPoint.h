#ifndef DriveToPoint_H
#define DriveToPoint_H

#include "../CommandBase.h"

class DriveToPoint : public CommandBase {
public:
	DriveToPoint();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // DriveToPoint_H

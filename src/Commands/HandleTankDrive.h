#ifndef HandleTankDrive_H
#define HandleTankDrive_H

#include "../CommandBase.h"

class HandleTankDrive : public CommandBase {
public:
	HandleTankDrive();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // HandleTankDrive_H
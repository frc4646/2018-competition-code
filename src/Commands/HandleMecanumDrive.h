#ifndef HandleDrive_H
#define HandleDrive_H

#include "../CommandBase.h"

class HandleDrive : public CommandBase {
public:
	HandleDrive();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // HandleDrive_H

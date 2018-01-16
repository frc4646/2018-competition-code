#ifndef HandleMecanumDrive_H
#define HandleMecanumDrive_H

#include "../CommandBase.h"

class HandleMecanumDrive : public CommandBase {
public:
	HandleMecanumDrive();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // HandleMecanumDrive_H

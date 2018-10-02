#ifndef HoldLift_H
#define HoldLift_H

#include <CommandBase.h>

class HoldLift : public CommandBase {
public:
	HoldLift();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // HoldLift_H

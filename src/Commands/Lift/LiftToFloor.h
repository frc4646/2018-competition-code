#ifndef LiftToFloor_H
#define LiftToFloor_H

#include <CommandBase.h>

class LiftToFloor : public CommandBase {
public:
	LiftToFloor();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // LiftToFloor_H

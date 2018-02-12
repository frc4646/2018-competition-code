#ifndef LiftToSwitch_H
#define LiftToSwitch_H

#include <CommandBase.h>

class LiftToSwitch : public CommandBase {
public:
	LiftToSwitch();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // LiftToSwitch_H

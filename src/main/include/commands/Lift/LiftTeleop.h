#ifndef LiftDown_H
#define LiftDown_H

#include <CommandBase.h>

class LiftTeleop : public CommandBase {
public:
	LiftTeleop();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // LiftDown_H

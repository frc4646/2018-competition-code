#ifndef LiftDown_H
#define LiftDown_H

#include <CommandBase.h>

class LiftDown : public CommandBase {
public:
	LiftDown();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // LiftDown_H

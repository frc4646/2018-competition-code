#ifndef LiftToScale_H
#define LiftToScale_H

#include <CommandBase.h>

class LiftToScale : public CommandBase {
public:
	LiftToScale();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // LiftToScale_H

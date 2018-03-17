#ifndef LiftToHeight_H
#define LiftToHeight_H

#include <CommandBase.h>

class LiftToHeight : public CommandBase {
public:
	LiftToHeight(double height);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // LiftToHeight_H

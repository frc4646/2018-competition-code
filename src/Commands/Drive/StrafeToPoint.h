#ifndef StrafeToPoint_H
#define StrafeToPoint_H

#include <CommandBase.h>

class StrafeToPoint : public CommandBase {
public:
	StrafeToPoint();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // StrafeToPoint_H

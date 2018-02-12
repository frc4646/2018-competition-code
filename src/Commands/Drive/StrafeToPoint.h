#ifndef StrafeToPoint_H
#define StrafeToPoint_H

#include <CommandBase.h>

class StrafeToPoint : public CommandBase {
public:
	StrafeToPoint(double distance);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // StrafeToPoint_H

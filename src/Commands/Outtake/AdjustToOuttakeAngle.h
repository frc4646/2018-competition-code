#ifndef AdjustToOuttakeAngle_H
#define AdjustToOuttakeAngle_H

#include <CommandBase.h>

class AdjustToOuttakeAngle : public CommandBase {
public:
	AdjustToOuttakeAngle();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // AdjustToOuttakeAngle_H

#ifndef AdjustToIntakeAngle_H
#define AdjustToIntakeAngle_H

#include "../CommandBase.h"

class AdjustToIntakeAngle : public CommandBase {
public:
	AdjustToIntakeAngle();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // AdjustToIntakeAngle_H

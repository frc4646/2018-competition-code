#ifndef IntakeAngleAdjust_H
#define IntakeAngleAdjust_H

#include "../../CommandBase.h"

class IntakeAngleAdjust : public CommandBase {
public:
	IntakeAngleAdjust();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // IntakeAngleAdjust_H

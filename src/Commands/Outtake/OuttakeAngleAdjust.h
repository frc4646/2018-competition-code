#ifndef OuttakeAngleAdjust_H
#define OuttakeAngleAdjust_H

#include "../CommandBase.h"

class OuttakeAngleAdjust : public CommandBase {
public:
	OuttakeAngleAdjust();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // OuttakeAngleAdjust_H

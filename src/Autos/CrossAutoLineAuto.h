#ifndef CrossAutoLineAuto_H
#define CrossAutoLineAuto_H

#include "../CommandBase.h"
#include <Timer.h>
#include "IDriveTrain.h"

class CrossAutoLineAuto : public CommandBase {
private:
	Timer timer;
	double driveTime;
public:
	CrossAutoLineAuto();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // CrossAutoLineAuto_H

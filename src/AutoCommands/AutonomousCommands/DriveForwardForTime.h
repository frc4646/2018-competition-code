#ifndef DriveForwardForTime_H
#define DriveForwardForTime_H

#include "CommandBase.h"
#include "Timer.h"

class DriveForwardForTime : public CommandBase {
private:
	double time;
	Timer timer;
public:
	DriveForwardForTime(double t);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // DriveForwardForTime_H

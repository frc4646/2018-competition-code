#ifndef DriveForwardForTime_H
#define DriveForwardForTime_H

#include "CommandBase.h"
#include "Timer.h"

class DriveForTime : public CommandBase {
private:
	double time;
	bool _back;
	Timer timer;
public:
	DriveForTime(double t, bool back);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // DriveForwardForTime_H

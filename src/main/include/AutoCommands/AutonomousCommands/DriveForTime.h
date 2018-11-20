#ifndef DriveForwardForTime_H
#define DriveForwardForTime_H

#include "CommandBase.h"
#include <frc/Timer.h>

class DriveForTime : public CommandBase {
private:
	double time;
	bool _back;
	frc::Timer timer;
public:
	DriveForTime(double t, bool back);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // DriveForwardForTime_H

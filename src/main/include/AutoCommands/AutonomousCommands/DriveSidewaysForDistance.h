#ifndef DriveSidewaysForDistance_H
#define DriveSidewaysForDistance_H

#include <CommandBase.h>

class DriveSidewaysForDistance : public CommandBase {
private:
	double dist;
public:
	DriveSidewaysForDistance(double distance);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // DriveSidewaysForDistance_H

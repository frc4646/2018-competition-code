#ifndef LaunchAngleAdjust_H
#define LaunchAngleAdjust_H

#include <CommandBase.h>

class LaunchAngleAdjust : public CommandBase {
public:
	LaunchAngleAdjust();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // LaunchAngleAdjust_H

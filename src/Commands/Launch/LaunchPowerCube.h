#ifndef LaunchPowerCube_H
#define LaunchPowerCube_H

#include <CommandBase.h>

class LaunchPowerCube : public CommandBase {
public:
	LaunchPowerCube();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // LaunchPowerCube_H

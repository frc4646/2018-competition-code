#ifndef IntakePowerCube_H
#define IntakePowerCube_H

#include <CommandBase.h>

class IntakePowerCube : public CommandBase {
public:
	IntakePowerCube();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // IntakePowerCube_H

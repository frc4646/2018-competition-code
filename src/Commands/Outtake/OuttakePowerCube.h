#ifndef OuttakePowerCube_H
#define OuttakePowerCube_H

#include <CommandBase.h>

class OuttakePowerCube : public CommandBase {
public:
	OuttakePowerCube();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // OuttakePowerCube_H

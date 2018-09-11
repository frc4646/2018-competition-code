#ifndef OuttakePowerCube_H
#define OuttakePowerCube_H

#include <CommandBase.h>
#include <Timer.h>

class OuttakePowerCube : public CommandBase {
private:
	Timer timer;
public:
	OuttakePowerCube();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // OuttakePowerCube_H

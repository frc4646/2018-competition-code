#ifndef OuttakePowerCube_H
#define OuttakePowerCube_H

#include <CommandBase.h>
#include <frc/Timer.h>

class OuttakePowerCube : public CommandBase {
private:
	frc::Timer timer;
public:
	OuttakePowerCube();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // OuttakePowerCube_H

#ifndef HandleMecanumDrive_H
#define HandleMecanumDrive_H

#include <CommandBase.h>

using namespace loop;

class HandleMecanumDrive : public CommandBase {
private:

	double joyDB;
	bool joytar;
	static float target;
	static bool trackTarget;
	const double defaultJoyDB = 0.1;

public:
	HandleMecanumDrive();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // HandleMecanumDrive_H


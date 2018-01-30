#ifndef HandleMecanumDrive_H
#define HandleMecanumDrive_H

#include <CommandBase.h>

using namespace loop;

class HandleMecanumDrive : public CommandBase {
private:
	double joyDB;
	bool joytar;

	const double defaultP = 0.045;
	const double defaultMaxCommand = 0.75;
	const double defaultMinCommand = 0.1;
	const double deltaDegree = 1.5;
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

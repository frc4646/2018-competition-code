#ifndef CrossAutoLineAuto_H
#define CrossAutoLineAuto_H

#include <CommandBase.h>
#include <Timer.h>
#include <Subsystems/Drivetrain/IDriveTrain.h>

using namespace loop;

class CrossAutoLineAuto : public CommandBase {
private:
	Timer timer;
	double driveTime;
public:
	CrossAutoLineAuto();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // CrossAutoLineAuto_H

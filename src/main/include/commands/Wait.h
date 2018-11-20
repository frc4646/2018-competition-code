#ifndef Wait_H
#define Wait_H

#include <CommandBase.h>
#include <frc/Timer.h>

class Wait : public CommandBase {
private:
	frc::Timer timer;
	double _time;
public:
	Wait(double time);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // Wait_H

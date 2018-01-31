#ifndef RotateToPoint_H
#define RotateToPoint_H

#include <CommandBase.h>

class RotateToPoint : public CommandBase {
private:
	double target;
public:
	RotateToPoint(double angle);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // RotateToPoint_H

#ifndef DriveToPoint_H
#define DriveToPoint_H

#include <CommandBase.h>

class DriveToPoint : public CommandBase {
private:
	double tx, ty, theta, dist;
	enum State {
		TURNING_TO_THETA,
		DRIVING_TO_DIST
	};
	State state;
public:
	DriveToPoint(double x, double y);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

};

#endif  // DriveToPoint_H

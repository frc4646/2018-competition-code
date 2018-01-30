#ifndef AngleAdjust_H
#define AngleAdjust_H

#include "../CommandBase.h"

class AngleAdjust : public CommandBase {
private:
	double a;
public:
	AngleAdjust(double angle);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // AngleAdjust_H

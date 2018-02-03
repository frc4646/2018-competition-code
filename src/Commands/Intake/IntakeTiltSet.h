#ifndef IntakePower_H
#define IntakePower_H

#include <CommandBase.h>
#include <OI.h>

class IntakeTiltSet : public CommandBase {
public:
	IntakeTiltSet();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // IntakePower_H

#ifndef IntakePower_H
#define IntakePower_H

#include <CommandBase.h>
#include <OI.h>

class IntakePowerSet : public CommandBase {
public:
	IntakePowerSet();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // IntakePower_H

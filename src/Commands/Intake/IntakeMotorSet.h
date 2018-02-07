#ifndef IntakeMotorSet_H
#define IntakeMotorSet_H

#include <CommandBase.h>
#include <OI.h>

class IntakeMotorSet : public CommandBase {
public:
	IntakeMotorSet();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // IntakeMotorSet_H

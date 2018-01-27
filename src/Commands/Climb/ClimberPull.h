#ifndef ClimberPull_H
#define ClimberPull_H

#include "../CommandBase.h"

class ClimberPull : public CommandBase {
public:
	ClimberPull();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // ClimberPull_H

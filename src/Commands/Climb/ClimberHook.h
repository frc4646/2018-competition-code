#ifndef ClimberHook_H
#define ClimberHook_H

#include <CommandBase.h>

class ClimberHook : public CommandBase {
public:
	ClimberHook();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // ClimberHook_H

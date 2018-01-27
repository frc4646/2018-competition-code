#ifndef ClimberRaise_H
#define ClimberRaise_H

#include "../CommandBase.h"

class ClimberRaise : public CommandBase {
public:
	ClimberRaise();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // ClimberRaise_H

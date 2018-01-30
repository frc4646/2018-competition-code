#ifndef Idle_H
#define Idle_H

#include "../CommandBase.h"

class Idle : public CommandBase {
public:
	Idle(int numRequires, ...);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // Idle_H

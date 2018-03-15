#ifndef Kickstand_H
#define Kickstand_H

#include "CommandBase.h"
#include "Timer.h"

class Kickstand : public CommandBase {
public:
	Kickstand();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	Timer timer;
};

#endif  // Kickstand_H

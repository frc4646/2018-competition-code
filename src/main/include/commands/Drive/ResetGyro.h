#ifndef ResetGyro_H
#define ResetGyro_H

#include <CommandBase.h>

class ResetGyro : public CommandBase {
public:
	ResetGyro();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // ResetGyro_H

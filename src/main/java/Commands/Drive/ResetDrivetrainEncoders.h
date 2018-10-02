#ifndef ResetDrivetrainEncoders_H
#define ResetDrivetrainEncoders_H

#include <CommandBase.h>

class ResetDrivetrainEncoders : public CommandBase {
public:
	ResetDrivetrainEncoders();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // ResetDrivetrainEncoders_H

#ifndef HandleMecanumDrive_H
#define HandleMecanumDrive_H

#include "../CommandBase.h"

using namespace loop;

class HandleMecanumDrive : public CommandBase {
public:
	HandleMecanumDrive();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
	/*static void ShouldRunTargeting(bool enabled);
	static bool IsTargeting();
	static void SetTarget(float target);*/

	static float target;
	static bool trackTarget;
};

#endif  // HandleMecanumDrive_H

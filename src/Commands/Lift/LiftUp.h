<<<<<<< HEAD
#ifndef LiftUp_H
#define LiftUp_H

#include <CommandBase.h>
#include "Subsystems/Lift/LiftControl.h"

class LiftUp : public CommandBase {
public:
	LiftUp();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // LiftUp_H
=======
#ifndef LiftUp_H
#define LiftUp_H

#include <CommandBase.h>

class LiftUp : public CommandBase {
public:
	LiftUp();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // LiftUp_H
>>>>>>> 7c4ef7586961181d848fb171a63752b73ecdac32

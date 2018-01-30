#ifndef IntakeControl_H
#define IntakeControl_H

#include <Commands/Subsystem.h>

class IntakeControl : public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities

public:
	IntakeControl();
	void InitDefaultCommand();
};

#endif  // IntakeControl_H

#ifndef IntakeControl_H
#define IntakeControl_H


#include <Commands/Subsystem.h>

#include <Spark.h>
#include <DigitalInput.h>
#include <PinEnums.h>
#include <LOOP/PID.h>

using namespace loop;

class IntakeControl : public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	Spark intake;

public:
	IntakeControl(MotorPin in, MotorPin tilt, DIOPin limit);
	void InitDefaultCommand();
	void SetIntakePower(double power);

public:
	IntakeControl();
	//void InitDefaultCommand();
};

#endif  // IntakeControl_H

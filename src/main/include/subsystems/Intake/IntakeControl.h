#ifndef IntakeControl_H
#define IntakeControl_H


#include <frc/Commands/Subsystem.h>

#include <frc/Spark.h>
#include <frc/DigitalInput.h>
#include <PinEnums.h>
#include <LOOP/PID.h>

using namespace loop;

class IntakeControl : public frc::Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	frc::Spark intakeMotor;

public:
	IntakeControl(MotorPin in, DIOPin limit);
	void InitDefaultCommand();
	void SetIntakePower(double power);

public:
	IntakeControl();
	//void InitDefaultCommand();
};

#endif  // IntakeControl_H

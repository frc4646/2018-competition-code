#include "IntakeControl.h"
#include "LOOP/Idle.h"
#include "LOOP/PID.h"

using namespace loop;

IntakeControl::IntakeControl(MotorPin in, DIOPin limit) :
		Subsystem("IntakeControl"),
		intakeMotor(in) {

}

void IntakeControl::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
	SetDefaultCommand(new Idle(1, CommandBase::intake.get()));
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

// Sets intake power to argument "power".
void IntakeControl::SetIntakePower(double power) {
	intakeMotor.Set(power);
}

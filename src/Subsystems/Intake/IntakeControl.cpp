#include "IntakeControl.h"
#include "LOOP/Idle.h"
#include "LOOP/PID.h"
#include <Commands/Intake/IntakeMotorSet.h>

using namespace loop;

IntakeControl::IntakeControl(MotorPin in, MotorPin tilt, DIOPin limit) :
		Subsystem("IntakeControl"),
		intake(in) {

}

void IntakeControl::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
	SetDefaultCommand(new IntakeMotorSet());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void IntakeControl::SetIntakePower(double power) {
	intake.Set(power);
}

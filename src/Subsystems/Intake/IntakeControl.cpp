#include "IntakeControl.h"
#include "LOOP/Idle.h"
#include "LOOP/PID.h"

using namespace loop;

IntakeControl::IntakeControl(MotorPin in, MotorPin tilt, DIOPin limit) :
		Subsystem("IntakeControl"),
		intake(in),
		angle(tilt),
		limitSwitch(limit),
		anglePid(0.045, 1, 0) {
	anglePid.BindInput(CommandBase::intakeAngleSensor->GetAngle);
	anglePid.BindOutput(SetTiltPower);
}

void IntakeControl::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
	SetDefaultCommand(new Idle());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void IntakeControl::SetIntakePower(double power) {
	intake.Set(power);
}

bool IntakeControl::HasPowerCube() {
	return limitSwitch.Get();
}

void IntakeControl::SetTiltPower(double power) {
	angle.Set(power);
}

void IntakeControl::SetIntakeAngle(double theta) {
	anglePid.SetSetpoint(theta);
}

bool IntakeControl::IntakeIsAtTarget() {
	return CommandBase::intakeAngleSensor->GetAngle() > anglePid.GetSetpoint() - 2 && CommandBase::intakeAngleSensor->GetAngle() < anglePid.GetSetpoint() + 2;
}

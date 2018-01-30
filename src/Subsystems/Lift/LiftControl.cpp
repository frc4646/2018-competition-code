#include "LiftControl.h"
#include "LOOP/Idle.h"
#include "CommandBase.h"

using namespace loop;

LiftControl::LiftControl(MotorPin lifter) : Subsystem("LiftControl"),
		liftLifter(lifter),
		lifterTargetElevation(0),
		lifterMaxPower(1),
		liftPid(0.01, 0.1, 0) {

}

void LiftControl::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
	SetDefaultCommand(new Idle(CommandBase::lift));
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

/*void LiftControl::TiltToAngle(double angle) {
	tilterTargetAngle = std::min(std::max(0, angle), 120);
	tiltPid.SetSetpoint(angle);
}

void LiftControl::SetTiltMaxPower(double power) {
	tilterMaxPower = std::min(std::max(-1, power), 1);
}

double LiftControl::GetTiltAngle() {
	return tilterTargetAngle;
}*/

void LiftControl::LiftToElevation(double elevation) {
	lifterTargetElevation = std::min(std::max(0.0, elevation), 4.0);
}

void LiftControl::SetLiftMaxPower(double power) {
	lifterMaxPower = std::min(std::max(-1.0, power), 1.0);
}

double LiftControl::GetLiftElevation() {
	return lifterTargetElevation;
}

void LiftControl::StopLift() {
	SetLiftPower(0);
}

void LiftControl::SetLiftPower(double power) {
	liftLifter.Set(std::min(std::max(-lifterMaxPower, power), lifterMaxPower));
}

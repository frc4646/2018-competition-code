#include "LiftControl.h"
#include "LOOP/Idle.h"
#include "CommandBase.h"

using namespace loop;

LiftControl::LiftControl(MotorPin lifter) : Subsystem("LiftControl"),
		liftLifter(lifter){

}

void LiftControl::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
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
	//MLL - we should probably get our min and max values from the string pot class and not magic numbers.
}

void LiftControl::SetLiftMaxPower(double power) {
	//lifterMaxPower = std::min(std::max(-1.0, power), 1.0); MLL- Not sure what this is doing
}

double LiftControl::GetLiftElevation() {
	//return lifterTargetElevation; MLL- This is handled by the string pot. Maybe this function just needs to be renamed
	return 0;
}

void LiftControl::StopLift() {
	// SetLiftPower(0); MLL - The lift needs to maintain its position by continuing to run the PID, gravity is working against this
}

void LiftControl::SetLiftPower(double power) {
	liftLifter.Set(std::min(std::max(-lifterMaxPower, power), lifterMaxPower));
	//MLL - We may want to handle the minimum lifter power, and it may different up and down because gravity
}

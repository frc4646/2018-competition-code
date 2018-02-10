#include "LiftControl.h"
#include "LOOP/Idle.h"
#include "CommandBase.h"
#include "LOOP/PID.h"
#include "LiftStringPot.h"

using namespace loop;

LiftControl::LiftControl(MotorPin lifter, MotorPin ratchet) : Subsystem("LiftControl"),
		liftMotor(lifter),
		ratchetButtonServo(ratchet)
		{
			frc::SmartDashboard::PutNumber("Lifter P", defaultLiftUpP);
			frc::SmartDashboard::PutNumber("Lifter I", defaultLiftUpI);
			frc::SmartDashboard::PutNumber("Lifter D", defaultLiftUpD);
		lifterTargetElevation = CommandBase::liftStringPot->GetMinHeight();
}

void LiftControl::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void LiftControl::LiftToElevation(double elevation) {
	lifterTargetElevation = (std::min(std::max(elevation, CommandBase::liftStringPot->GetMinHeight()), CommandBase::liftStringPot->GetMaxHeight()));
}

double LiftControl::GetLiftElevation() {
	return CommandBase::liftStringPot->GetHeight();
}

void LiftControl::StopLift() {
	lifterTargetElevation = GetLiftElevation();

}

void LiftControl::SetLiftPower(double power) {
	if (power > 0) {
		liftMotor.Set(std::min(std::max(lifterMinPowerUp, power), lifterMaxPowerUp));
	}

	else if(power < 0) {
		liftMotor.Set(std::min(std::max(lifterMinPowerDown, power), lifterMaxPowerDown));
	}

	else {
		StopLift();
	}

}

void LiftControl::Lift() {
	//pid
}

void LiftControl::SetRatchetEngage(bool on) {
	//when the ratchet is engaged, the button is not pressed
	if (on == true) {
		ratchetButtonServo.SetAngle(ratchetOnAngle);
	}

	else {
		ratchetButtonServo.SetAngle(ratchetOffAngle);
	}
}

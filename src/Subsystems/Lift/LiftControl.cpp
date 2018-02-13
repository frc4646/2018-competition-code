#include "LiftControl.h"
#include "LOOP/Idle.h"
#include "CommandBase.h"
#include "Subsystems/PID4646.h"
#include "LiftStringPot.h"
#include "Commands/Lift/HoldLift.h"

using namespace loop;

LiftControl::LiftControl(MotorPin lifter, MotorPin ratchet) : Subsystem("LiftControl"),
		liftMotor(lifter),
		ratchetButtonServo(ratchet),
		liftHeightPID()
		{
			frc::SmartDashboard::PutNumber(dashboard_Lifter_P_up, defaultLiftUpP);
			frc::SmartDashboard::PutNumber(dashboard_Lifter_I_up, defaultLiftUpI);
			frc::SmartDashboard::PutNumber(dashboard_Lifter_D_up, defaultLiftUpD);
			frc::SmartDashboard::PutNumber(dashboard_Lifter_P_down, defaultLiftDownP);
			frc::SmartDashboard::PutNumber(dashboard_Lifter_I_down, defaultLiftDownI);
			frc::SmartDashboard::PutNumber(dashboard_Lifter_D_down, defaultLiftDownD);
			frc::SmartDashboard::PutNumber(dashboard_Lifter_D_update_rate, defaultLiftDUpdateRate);
			liftHeightPID.SetController_Positive(PID4646::Controller{
				frc::SmartDashboard::GetNumber(dashboard_Lifter_P_up, defaultLiftUpP),
				frc::SmartDashboard::GetNumber(dashboard_Lifter_I_up, defaultLiftUpI),
				frc::SmartDashboard::GetNumber(dashboard_Lifter_D_up, defaultLiftUpD),
				lifterMinPowerUp,
				lifterMaxPowerUp
			});
			liftHeightPID.SetController_Negative(PID4646::Controller{
				frc::SmartDashboard::GetNumber(dashboard_Lifter_P_down, defaultLiftDownP),
				frc::SmartDashboard::GetNumber(dashboard_Lifter_I_down, defaultLiftDownI),
				frc::SmartDashboard::GetNumber(dashboard_Lifter_D_down, defaultLiftDownD),
				lifterMinPowerDown,
				lifterMaxPowerDown
			});
			liftHeightPID.SetDUpdateRate(frc::SmartDashboard::GetNumber(dashboard_Lifter_D_update_rate, defaultLiftDUpdateRate));
		lifterTargetElevation = CommandBase::liftStringPot->GetMinHeight();
}

void LiftControl::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
	// Is this the right command? I see HoldLift and LiftTeleop.
	// -Christopher; (2/12/18)
	SetDefaultCommand(new HoldLift());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void LiftControl::LiftToElevation(double elevation) {
	lifterTargetElevation = (std::min(std::max(elevation, CommandBase::liftStringPot->GetMinHeight()), CommandBase::liftStringPot->GetMaxHeight()));
	liftHeightPID.SetTarget(lifterTargetElevation);
}

double LiftControl::GetLiftElevation() {
	return CommandBase::liftStringPot->GetHeight();
}

void LiftControl::StopLift() {
	// This method does its job, but may be mistaken for something that cuts motor power.
	// We may want to have an emergency StopLift that shuts off the motor in case the PID
	// goes awry. -Christopher; (2/12/18)

	//lifterTargetElevation = GetLiftElevation();
	LiftToElevation(GetLiftElevation());
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
	//pid? pid.
	SetLiftPower(liftHeightPID.UpdateControl(GetLiftElevation()));

	//TODO MLL This will need to always maintain the target position. I wrote a PID control that should
	// allow you to do it all. You can use it, or write your own.
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

void LiftControl::ResetLiftPIDControl() {
	liftHeightPID.ResetControl();
}

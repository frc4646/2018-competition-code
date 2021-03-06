#ifndef LiftControl_H
#define LiftControl_H

#include <Commands/Subsystem.h>
#include "Spark.h"
#include "PinEnums.h"
#include <WPILib.h>
#include <Subsystems/PID4646.h>
#include <Servo.h>



/*
 * LiftControl
 * Controls lift elevating and movement... things
 */

class LiftControl : public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities

	const llvm::StringRef dashboard_Lifter_P_up = "Lifter P (up)";
	const llvm::StringRef dashboard_Lifter_I_up = "Lifter I (up)";
	const llvm::StringRef dashboard_Lifter_D_up = "Lifter D (up)";
	const llvm::StringRef dashboard_Lifter_P_down = "Lifter P (down)";
	const llvm::StringRef dashboard_Lifter_I_down = "Lifter I (down)";
	const llvm::StringRef dashboard_Lifter_D_down = "Lifter D (down)";
	const llvm::StringRef dashboard_Lifter_D_update_rate = "Lifter D update rate";

	Spark liftMotor;
	const double lifterMaxPowerUp = .5;
	const double lifterMinPowerUp = 0.01;
	const double lifterMaxPowerDown = -.2;
	const double lifterMinPowerDown = -0.01;

	const double defaultLiftDUpdateRate = 0.1;

	const double defaultLiftUpP = 0.1;
	const double defaultLiftUpI = 0;
	const double defaultLiftUpD = 0;
	const PID4646::Controller defaultLiftUpPIDTunings = PID4646::Controller{defaultLiftUpP, defaultLiftUpI, defaultLiftUpD, lifterMinPowerUp, lifterMaxPowerUp};

	const double defaultLiftDownP = 0.1;
	const double defaultLiftDownI = 0;
	const double defaultLiftDownD = 0;
	const PID4646::Controller defaultLiftDownPIDTunings = PID4646::Controller{defaultLiftDownP, defaultLiftDownI, defaultLiftDownD, lifterMinPowerDown, lifterMaxPowerDown};

	double lifterTargetElevation;

	Servo ratchetButtonServo;
	//angles are just place holders
	const double ratchetOnAngle = 0;
	const double ratchetOffAngle = 90;

	PID4646 liftHeightPID;


public:
	LiftControl(MotorPin lifter, MotorPin ratchet);
	void InitDefaultCommand();
	void LiftToElevation(double elevation);
	double GetLiftElevation();
	void StopLift();
	void SetLiftPower(double power, bool override = false);
	void Lift();
	void SetRatchetEngage(bool on);
	void ResetLiftPIDControl();
};

#endif  // LiftControl_H

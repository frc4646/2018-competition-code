#ifndef LiftControl_H
#define LiftControl_H

#include <Commands/Subsystem.h>
#include "Spark.h"
#include "PinEnums.h"
#include <WPILib.h>
#include "LOOP/PID.h"


/*
 * LiftControl
 * Controls lift elevating and movement... things
 */

class LiftControl : public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities

	Spark liftLifter; //MLL Can we rename this to motor controller or something similar?
	const double lifterMaxPower = 1;
	const double lifterMinPower = 0;
	const double defaultLifterP = 0.1;
	const double defaultLifterI = 0;
	const double defaultLifterD = 0;
	loop::PID lifterPid;
	double lifterTargetElevation;

public:
	LiftControl(MotorPin lifter);
	void InitDefaultCommand();
	void LiftToElevation(double elevation);
	void SetLiftMaxPower(double power);
	double GetLiftElevation();
	void StopLift();
	void SetLiftPower(double power);
};

#endif  // LiftControl_H

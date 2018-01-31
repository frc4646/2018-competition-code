#ifndef LiftControl_H
#define LiftControl_H

#include <Commands/Subsystem.h>
#include "Spark.h"
#include "PinEnums.h"
#include "LOOP/PID.h"

using namespace loop;

/*
 * LiftControl
 * Controls lift elevating and movement... things
 */

class LiftControl : public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities

	Spark liftLifter;
	double lifterTargetElevation, lifterMaxPower;
	PID liftPid;

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

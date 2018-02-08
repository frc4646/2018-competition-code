#ifndef LiftControl_H
#define LiftControl_H

#include <Commands/Subsystem.h>
#include "Spark.h"
#include "PinEnums.h"
#include <WPILib.h>
#include "LOOP/PID.h"
#include <Servo.h>


/*
 * LiftControl
 * Controls lift elevating and movement... things
 */

class LiftControl : public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities

	Spark liftMotor;
	const double lifterMaxPowerUp = 1;
	const double lifterMinPowerUp = 0.01;
	const double lifterMaxPowerDown = -1;
	const double lifterMinPowerDown = -0.01;

	const double defaultLiftUpP = 0.1;
	const double defaultLiftUpI = 0;
	const double defaultLiftUpD = 0;

	const double defaultLiftDownP = 0.1;
	const double defaultLiftDownI = 0;
	const double defaultLiftDownD = 0;

	double lifterTargetElevation;

	Servo ratchetButtonServo;
	//angles are just place holders
	const double ratchetOnAngle = 0;
	const double ratchetOffAngle = 90;


public:
	LiftControl(MotorPin lifter, MotorPin ratchet);
	void InitDefaultCommand();
	void LiftToElevation(double elevation);
	double GetLiftElevation();
	void StopLift();
	void SetLiftPower(double power);
	void Lift();
	void SetRatchetEngage(bool on);
};

#endif  // LiftControl_H

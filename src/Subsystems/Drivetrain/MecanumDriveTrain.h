<<<<<<< HEAD
#ifndef MecanumDrive_H
#define MecanumDrive_H

#include <Commands/Subsystem.h>
#include <PinEnums.h>
#include <Spark.h>
#include <LOOP/IDriveTrain.h>
#include <LOOP/PID.h>
#include <LOOP/Binding.h>

using namespace loop;

class MecanumDriveTrain : public IDriveTrain {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	Spark fl;
	Spark fr;
	Spark bl;
	Spark br;
	double trackingAngle;
	bool doTracking;
	PID pid;
	//Spark revRoboticsBrandSparkPulseWidthModulationMotorControllerThatControlsTheCIMMotorThatIsOnPortZeroAndIsLocatedOnTheFrontLeftCornerOfTheRobotForThe2018SeasonAndIsConnectedToAPulseWidthModulationWireThatIsLabeledAs2YetIsConnectedToTheNationalInstrumentsRoboRIODigitalOutputPortZeroAndThisSparkController;
protected:
	void DoDrive(SDriveData driveData) override;

public:
	MecanumDriveTrain(MotorPin frontLeftPin, MotorPin frontRightPin, MotorPin backLeftPin, MotorPin backRightPin);
	void InitDefaultCommand() override;
	void Stop();

	void EnableTracking(bool enable);
	bool TrackingEnabled();
	void SetAngleTrackingTarget(double angle);
};

#endif  // MecanumDrive_H
=======
#ifndef MecanumDrive_H
#define MecanumDrive_H

#include <Commands/Subsystem.h>
#include <PinEnums.h>
#include <Spark.h>
#include <Subsystems/Drivetrain/IDriveTrain.h>
#include <LOOP/PID.h>
#include <LOOP/Binding.h>
#include <WPILib.h>

using namespace loop;

class MecanumDriveTrain : public IDriveTrain {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	Spark fl;
	Spark fr;
	Spark bl;
	Spark br;
	bool doTracking;
	double trackingAngle;
	PID pid;
	//Spark revRoboticsBrandSparkPulseWidthModulationMotorControllerThatControlsTheCIMMotorThatIsOnPortZeroAndIsLocatedOnTheFrontLeftCornerOfTheRobotForThe2018SeasonAndIsConnectedToAPulseWidthModulationWireThatIsLabeledAs2YetIsConnectedToTheNationalInstrumentsRoboRIODigitalOutputPortZeroAndThisSparkController;

public:
	MecanumDriveTrain(MotorPin frontLeftPin, MotorPin frontRightPin, MotorPin backLeftPin, MotorPin backRightPin);
	void InitDefaultCommand() override;
	void Stop();
	void Drive(SDriveData driveData) override;

	void EnableTracking(bool enable);
	bool TrackingEnabled();
	void SetAngleTrackingTarget(double angle);
};

#endif  // MecanumDrive_H
>>>>>>> 7c4ef7586961181d848fb171a63752b73ecdac32

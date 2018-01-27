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

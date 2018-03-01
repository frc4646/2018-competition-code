#ifndef MecanumDrive_H
#define MecanumDrive_H

#include <Commands/Subsystem.h>
#include <PinEnums.h>
#include <Spark.h>
#include <LOOP/IDriveTrain.h>
#include <LOOP/PID.h>
#include <LOOP/Binding.h>
#include <WPILib.h>
#include <IMU10Axis/ADIS16448_IMU.h>
#include <Encoder.h>
#include <Subsystems/EncoderChannels.h>
#include <Subsystems/PID4646.h>
#include <iterator>
#include <list>

using namespace loop;

class MecanumDriveTrain : public IDriveTrain {
	public: enum EncoderIndex : int;
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	Spark fl;
	Spark fr;
	Spark bl;
	Spark br;

	bool doAngleHold;
	double angleHoldTarget;
	double lastCartR;
	bool doTracking;
	double trackingAngle;
	bool targetMet;
	const double defaultP = 0.045;
	const double defaultMaxCommand = 0.75;
	const double defaultMinCommand = 0.1;
	const double deltaDegree = 0.5;
	const double cartRDeadband = 0.1;
	Encoder flEnc, frEnc, blEnc, brEnc;

	PID4646 flEncPID, frEncPID, blEncPID, brEncPID;
	bool runMotorsToTarget;
	ADIS16448_IMU gyro;

	const PID4646::Controller defaultFlTunings = PID4646::Controller {
		0.2,
		0,
		0,
		0,
		.2,
		0.5
	};
	const PID4646::Controller defaultFrTunings = PID4646::Controller {
		0.2,
		0,
		0,
		0,
		.2,
		0.5
	};
	const PID4646::Controller defaultBlTunings = PID4646::Controller {
		0.2,
		0,
		0,
		0,
		.2,
		0.5
	};
	const PID4646::Controller defaultBrTunings = PID4646::Controller {
		0.2,
		0,
		0,
		0,
		.2,
		0.5
	};

	std::list<Encoder*>::iterator EncoderForIndex(EncoderIndex whichEncoder);
	std::list<PID4646*>::iterator PIDForIndex(EncoderIndex whichEncoder);

	//Spark revRoboticsBrandSparkPulseWidthModulationMotorControllerThatControlsTheCIMMotorThatIsOnPortZeroAndIsLocatedOnTheFrontLeftCornerOfTheBellRingerRobotForTheTwoThousandAndSeventeenToTwoThousandAndEighteenOffseasonAndIsConnectedToAPulseWidthModulationWireThatIsLabeledAs2YetIsConnectedToTheNationalInstrumentsRoboRIODigitalOutputPortZeroAndThisSparkController;


public:
	// For purposes explained above, please leave the : int where it is. Thanks
	enum EncoderIndex : int {
		FRONT_LEFT = 0b0001,
		FRONT_RIGHT = 0b0010,
		BACK_LEFT = 0b0100,
		BACK_RIGHT = 0b1000
	};
	MecanumDriveTrain(MotorPin frontLeftPin, MotorPin frontRightPin, MotorPin backLeftPin, MotorPin backRightPin,
			EncoderChannels frontLeftEncoder, EncoderChannels frontRightEncoder, EncoderChannels backLeftEncoder, EncoderChannels backRightEncoder);
	void InitDefaultCommand() override;
	void Stop();

	void EnableTracking(bool enable);
	bool TrackingEnabled();
	void SetAngleTrackingTarget(double angle);
	bool AngleTrackingTargetMet();
	void ResetEncoders();
	void Drive(SDriveData driveData);

	double GetEncoderDistance(EncoderIndex whichEncoder);
	void SetEncoderTarget(EncoderIndex whichEncoder, double target);
	double GetEncoderTarget(EncoderIndex whichEncoder);
	void EnableRunToPosition(bool enable);
	bool RunToPositionEnabled();
	bool EncodersAtTarget(EncoderIndex whichEncoder);

	void ResetEncoderPIDs();
	void DumpEncoderValues();

	/*MLL - Here are some ideas for what we can do for encoders
	Set Strafe distance
	Set Drive distance
	Account for wheel slip by adjusting motor commands
	Control velocity

	The best way to get started is to get all 4 encoders installed, place the counts (and reset) in smartdashboard
	 then drive a KNOWN distance with the encoders, see what the counts get to, do it 2 or 3 times to get an average,
	 do the same thing with strafe.

	The next thing to do would be to drive at a known power for a known time and see the distance and encoder counts you get.
	Hopefully this gives you enough breadcrumbs to get started.
	*/
};

#endif  // MecanumDrive_H


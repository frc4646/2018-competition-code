#ifndef HandleMecanumDrive_H
#define HandleMecanumDrive_H

#include <CommandBase.h>

using namespace loop;

class HandleMecanumDrive : public CommandBase {
private:
	double joyDB;
	bool joytar;

	const double defaultP = 0.045;
	const double defaultMaxCommand = 0.75;
	const double defaultMinCommand = 0.1;
	const double deltaDegree = 1.5;
	const double defaultJoyDB = 0.1;

public:
	HandleMecanumDrive();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // HandleMecanumDrive_H

#ifndef HandleMecanumDrive_H
#define HandleMecanumDrive_H

#include <CommandBase.h>
#include <IMU10Axis/ADIS16448_IMU.h>

using namespace loop;

class HandleMecanumDrive : public CommandBase {
private:
	bool tarHeadingMode;
	float tar;
	//frc::ADXRS450_Gyro gyro;
	ADIS16448_IMU gyro;
	double joyDB;
	bool joytar;

	const double defaultP = 0.045;
	const double defaultMaxCommand = 0.75;
	const double defaultMinCommand = 0.1;
	const double deltaDegree = 1.5;
	const double defaultJoyDB = 0.1;

public:
	HandleMecanumDrive();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
	/*static void ShouldRunTargeting(bool enabled);
	static bool IsTargeting();
	static void SetTarget(float target);*/

	static float target;
	static bool trackTarget;
};

#endif  // HandleMecanumDrive_H


#ifndef HandleMecanumDrive_H
#define HandleMecanumDrive_H

#include "../CommandBase.h"

class HandleMecanumDrive : public CommandBase {
private:
	frc::ADXRS450_Gyro gyro;
	bool tarHeadingMode;
	float tar;
	const double defaultP = 0.045;
	const double defaultMaxCommand = 0.75;
	const double defaultMinCommand = 0.2;
	const double deltaDegree = 1.5;

public:
	HandleMecanumDrive();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // HandleMecanumDrive_H

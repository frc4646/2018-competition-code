#ifndef IDriveTrain_H
#define IDriveTrain_H

#include <Commands/Subsystem.h>
#include "ADXRS450_Gyro.h"

namespace loop {
	typedef struct {
		/*
		 * SDriveData structure.
		 */
		// Cartesian X
		double cartX;
		// Cartesian Y
		double cartY;
		// Cartesian rotation
		double cartR;
		// Left tank
		double lTank;
		// Right tank
		double rTank;
	} SDriveData;
	class IDriveTrain : public Subsystem {
	private:
		// It's desirable that everything possible under private except
		// for methods that implement subsystem capabilities
	protected:
		ADXRS450_Gyro gyro;

	public:
		IDriveTrain(std::string name);
		virtual void InitDefaultCommand() = 0;
		virtual void Stop() = 0;
		virtual void Drive(SDriveData driveData) = 0;
		double GetAngle();
	};
}

#endif  // IDriveTrain_H

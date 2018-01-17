/*
 * PID.h
 *
 *  Created on: Jan 17, 2018
 *      Author: christopher.johnson
 */

#ifndef SRC_LOOPCORE_PID_H_
#define SRC_LOOPCORE_PID_H_

#include <PIDOutput.h>
#include <PIDSource.h>
#include <PIDController.h>

class PID: public frc::PIDSource, public frc::PIDOutput {
private:
	double inputBuffer;
	double outputBuffer;
	PIDController controller;
protected:
	double PIDGet() override;
	void PIDWrite(double output) override;
public:
	PID(double p, double i, double d);
	void SetSetpoint(double setpoint);
};

#endif /* SRC_LOOPCORE_PID_H_ */

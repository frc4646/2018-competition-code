
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
#include <functional>

namespace loop {
class PID: public frc::PIDSource, public frc::PIDOutput {
private:
	double inputBuffer;
	double outputBuffer;
	PIDController controller;
	std::function<double (void)> input;
	std::function<void (double)> outp;
protected:
	double PIDGet() override;
	void PIDWrite(double output) override;
public:
	PID(double p, double i, double d);
	void SetSetpoint(double setpoint);
	double GetOutput();
	void SetInput(double input);
	void BindInput(std::function<double (void)> inp);
	void BindOutput(std::function<void (double)> out);
	double GetSetpoint();
};
}

#endif /* SRC_LOOPCORE_PID_H_ */

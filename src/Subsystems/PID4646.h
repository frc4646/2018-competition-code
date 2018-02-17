/*
 * PID4646.h
 *
 *  Created on: Feb 11, 2018
 *      Author: Megan
 */

#ifndef SRC_SUBSYSTEMS_PID4646_H_
#define SRC_SUBSYSTEMS_PID4646_H_

#include <queue>

class PID4646 {
public:
	PID4646();

	struct Controller
	{
		double P_Gain;
		double I_Gain;
		double D_Gain;
		double F_Gain;

		double Min_Cmd;
		double Max_Cmd;
	};

	void SetController(Controller PIDF);

	void SetController_Positive(Controller PIDF);
	void SetController_Negative(Controller PIDF);

	double UpdateControl(double signal);

	void SetTarget(double setpoint);
	void SetTolerance(double tolerance);
	void SetDUpdateRate(double rate);
	bool AtTarget();

	void ResetControl();
	void DumpIntegrator();

	double GetTarget();

private:
	Controller PositivePIDF;
	Controller NegativePIDF;

	double D_Update_Rate;
	std::queue<double> timeList;
	std::queue<double> errorList;

	double accumulatedError;
	double lastTimeStamp_I;
	double lastError_I;

	double deadband;
	double target;
	bool atTarget;
};

#endif /* SRC_SUBSYSTEMS_PID4646_H_ */

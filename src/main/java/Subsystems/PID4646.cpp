/*
 * PID4646.cpp
 *
 *  Created on: Feb 11, 2018
 *      Author: Megan
 *
 *  Optimized a little by Christopher
 */

#include <Subsystems/PID4646.h>
#include <Timer.h>
#include <math.h>
#include <iostream>

PID4646::Controller defaultPID =
{
		1, //Proportional Gain
		0, //Integral Gain
		0, //Derivative Gain
		0, //Feed-forward Gain

		0, //Minimum Command
		1  //Maximum Command
};

PID4646::PID4646() {
	SetController(defaultPID);
	SetTarget(0);
	SetTolerance(0);
	SetDUpdateRate(0);
	ResetControl();
}

void PID4646::SetController(Controller PIDF)
{
	PositivePIDF = PIDF;
	NegativePIDF = PIDF;
	NegativePIDF.Max_Cmd = NegativePIDF.Max_Cmd * -1;
	NegativePIDF.Min_Cmd = NegativePIDF.Min_Cmd * -1;

	ResetControl();
}

void PID4646::SetController_Positive(Controller PIDF)
{
	PositivePIDF = PIDF;
	ResetControl();

}
void PID4646::SetController_Negative(Controller PIDF)
{
	NegativePIDF = PIDF;
	ResetControl();

}

double PID4646::UpdateControl(double signal)
{
	double cmd = 0;
	double error = target - signal;
	double P_cmd = 0;
	double I_cmd = 0;
	double D_cmd = 0;
	double F_cmd = 0;
	double currentTime = frc::Timer::GetFPGATimestamp();
	// Instead of having multiple if statements, just have one -Christopher; (2/12/18)
	Controller applicablePIDF = (error > 0) ? PositivePIDF : NegativePIDF;

	if(abs(error) > deadband)
	{
		/*Proportional Control
		  ---------------------
		  The instantaneous difference between the target and current signal
		  P_cmd = P * Error*/
		P_cmd = applicablePIDF.P_Gain * error;

		/*Integral Control
		  ---------------------
		  The accumulated difference between the target and current signal
		  This controller is using a trapezoidal approximation for the accumulator
		  Be sure to reset the accumulator upon beginning a new control sequence,
		  you can do this either through the ResetErrors command or the DumpIntegrator command
		  I_cmd = I * Accumulated_Error*/

		//Accumulate the error
		if(lastTimeStamp_I > 0)
		{
			accumulatedError += (lastError_I + error)*(currentTime - lastTimeStamp_I)/2;

			I_cmd = applicablePIDF.I_Gain * accumulatedError;
		}
		else
		{
			I_cmd = 0;
		}
		lastTimeStamp_I = currentTime;
		lastError_I = error;

		/*Derivative Control
		  ---------------------
		  The rate of change between the target and current signal
		  To have a smooth D term, adjust the D time period to be AT LEAST
		  as long as the update period of the feedback signal.
		  D_cmd = D * Rate of Error Change*/
		if(timeList.size() > 0)
		{
			double oldestTime = timeList.front();
			double oldestError = errorList.front();
			double deltaT = currentTime - oldestTime;

			double rate_change = (error - oldestError) / deltaT;

			if(deltaT > D_Update_Rate)
			{
				//We don't need these elements anymore as they are older than our update rate
				timeList.pop();
				errorList.pop();
			}

			D_cmd = applicablePIDF.D_Gain * rate_change;
		}
		else
		{
			//Some how our list got cleared with nothing in it... Don't command anything
			D_cmd = 0;
		}
		timeList.push(currentTime);
		errorList.push(error);

		/*Feed-Forward Control
		 -------------------
		 Gain that is a command, most likely not needed in most circumstances*/
		F_cmd = applicablePIDF.F_Gain;

		if (error > 0) {
			cmd = std::min(std::max(P_cmd + I_cmd + D_cmd + F_cmd, applicablePIDF.Min_Cmd), applicablePIDF.Max_Cmd);
		} else {
			cmd = std::max(std::min(P_cmd + I_cmd + D_cmd + F_cmd, applicablePIDF.Min_Cmd), applicablePIDF.Max_Cmd);
		}
	}
	else
	{
		cmd = 0;
		atTarget = true;
	}

	std::cout << cmd << std::endl;
	return cmd;
}

void PID4646::SetTarget(double setpoint)
{
	target = setpoint;
}
void PID4646::SetTolerance(double tolerance)
{
	deadband = tolerance;
}
void PID4646::SetDUpdateRate(double rate)
{
	D_Update_Rate = rate;
}
bool PID4646::AtTarget()
{
	return atTarget;
}

void PID4646::ResetControl()
{
	// C and C++ interpret values greater than 0 as true, and 0 as false.
	// Thus, this while loop works. -Christopher; (2/12/18)
	while(timeList.size())
	{
		timeList.pop();
	}
	while(errorList.size())
	{
		errorList.pop();
	}

	atTarget = false;
	DumpIntegrator();
}

void PID4646::DumpIntegrator()
{
	//Resets just the integrator control
	lastTimeStamp_I = -1;
	lastError_I = 0;
	accumulatedError = 0;
}

double PID4646::GetTarget() {
	return target;
}

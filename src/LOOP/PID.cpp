/*
 * PID.cpp
 *
 *  Created on: Jan 17, 2018
 *      Author: christopher.johnson
 */

#include "PID.h"

PID::PID(double p, double i, double d) :
	PIDSource(),
	PIDOutput(),
	inputBuffer(0),
	outputBuffer(0),
	controller(p, i, d, this, this),
	input(NULL),
	outp(NULL) {
	controller.SetContinuous(true);
}

double PID::PIDGet() {
	if (input != NULL) {
		return input();
	}
	return inputBuffer;
}

void PID::PIDWrite(double output) {
	if (outp != NULL) {
		outp(output);
	}
	outputBuffer = output;
}

void PID::SetSetpoint(double setpoint) {
	controller.SetSetpoint(setpoint);
}

double PID::GetOutput() {
	return outputBuffer;
}

void PID::SetInput(double input) {
	inputBuffer = input;
}

void PID::BindInput(std::function<double (void)> inp) {
	input = inp;
}

void PID::BindOutput(std::function<void (double)> out) {
	outp = out;
}

void PID::GetSetpoint() {
	return controller.GetSetpoint();
}

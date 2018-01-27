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
	controller(p, i, d, this, this) {
	controller.SetContinuous(true);
}

double PID::PIDGet() {
	return inputBuffer;
}

void PID::PIDWrite(double output) {
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

/*
 * Utils.cpp
 *
 *  Created on: Feb 17, 2018
 *      Author: christopher.johnson
 */

#include <LOOP/Utils.h>
#include <cstdarg>

namespace loop {

bool close_enough(int threshold, int numConditions, ...) {
	int count = 0;
	va_list conditions;
	va_start(conditions, numConditions);
	for (int i = 0; i < numConditions; i++) {
		count += va_arg(conditions, int);
	}
	va_end(conditions);
	return count >= threshold;
}

double applyDeadband(double value, double deadband) {
	if (value < deadband && value > -deadband) {
		return 0;
	}
	return value;
}

bool withinRange(double value, double rangeLow, double rangeHigh) {
	return (value >= rangeLow && value <= rangeHigh);
}

};

/*
 * Utils.h
 *
 *  Created on: Feb 17, 2018
 *      Author: christopher.johnson
 */

#ifndef SRC_LOOP_UTILS_H_
#define SRC_LOOP_UTILS_H_

namespace loop {

bool close_enough(int threshold, int numConditions, ...);
double applyDeadband(double value, double deadband);
bool withinRange(double value, double rangeHigh, double rangeLow);

};

#endif /* SRC_LOOP_UTILS_H_ */

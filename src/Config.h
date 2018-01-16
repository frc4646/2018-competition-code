/*
 * Config.h
 *
 *  Created on: Jan 8, 2018
 *      Author: christopher.johnson
 *
 *  Config.h replaces RobotMap.h, and then some.
 */

#ifndef Config_H
#define Config_H

#include "PinEnums.h"

// Uncomment to enable gamepad control
//#define GAMEPAD

// DRIVETRAIN is the name of the drive train class.
// DRIVETRAIN_INIT_PARAMS is the parameters for the drive train's constructor.
// This might be merged into a single #define that is the entire constructor statement.
#define DRIVETRAIN MecanumDriveTrain
#define DRIVETRAIN_INIT_PARAMS frontLeftPin, frontRightPin, backLeftPin, backRightPin

const int frontLeftPin = M0;
const int frontRightPin = M1;
const int backLeftPin = M2;
const int backRightPin = M3;

#endif /* Config_H */

<<<<<<< HEAD
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

const MotorPin frontLeftPin = M0;
const MotorPin frontRightPin = M1;
const MotorPin backLeftPin = M2;
const MotorPin backRightPin = M3;

#define LIFT_INIT_PARAMS liftTilterPin, liftLifterPin

const MotorPin liftTilterPin = M4;
const MotorPin liftLifterPin = M5;
const double liftMovementFactor = 0.1;

#define INTAKE_INIT_PARAMS intakeIn, intakeIn, intakeLimit

const MotorPin intakeIn = M6;
const DIOPin intakeLimit = D0;

#endif /* Config_H */
=======
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

const MotorPin frontLeftPin = M0;
const MotorPin frontRightPin = M1;
const MotorPin backLeftPin = M2;
const MotorPin backRightPin = M3;

#endif /* Config_H */
>>>>>>> 7c4ef7586961181d848fb171a63752b73ecdac32

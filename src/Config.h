
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
#include "Subsystems/EncoderChannels.h"

// Uncomment to enable gamepad control
//#define GAMEPAD

// DRIVETRAIN is the name of the drive train class.
// DRIVETRAIN_INIT_PARAMS is the parameters for the drive train's constructor.
// This might be merged into a single #define that is the entire constructor statement.
#define DRIVETRAIN MecanumDriveTrain
#define DRIVETRAIN_INIT_PARAMS frontLeftPin, frontRightPin, backLeftPin, backRightPin, frontLeftEncoders, frontRightEncoders, backLeftEncoders, backRightEncoders
const MotorPin frontLeftPin = M0;
const MotorPin frontRightPin = M1;
const MotorPin backLeftPin = M2;
const MotorPin backRightPin = M3;
const EncoderChannels frontLeftEncoders = {
	D0,
	D1
};
const EncoderChannels frontRightEncoders = {
	D2,
	D3
};
const EncoderChannels backLeftEncoders = {
	D4,
	D5
};
const EncoderChannels backRightEncoders = {
	D6,
	D7
};

//#define LIFT_INIT_PARAMS liftTilterPin, liftLifterPin
#define LIFT_INIT_PARAMS liftLifterPin


const MotorPin liftLifterPin = M6;
const double liftMovementFactor = 0.1;

#define INTAKE_INIT_PARAMS intakePin, intakeTilterPin, intakeLimit

const MotorPin intakeTilterPin = M4;
const MotorPin intakePin = M5;
const DIOPin intakeLimit = D0;

#define LIFT_STRING_POT_INIT_PARAMS stringPotPin

const AnalogPin stringPotPin = A0;

#define ULTRASONIC_INIT_PARAMS ultrasonicPin

const AnalogPin ultrasonicPin = A1;

#endif /* Config_H */

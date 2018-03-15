
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
#include <WPILib.h>
#define PI 3.141592

#define PRACTICE_BOT

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

#define LIFT_INIT_PARAMS liftMotorPin, ratchetMotorPin

const MotorPin liftMotorPin = M5;
const MotorPin ratchetMotorPin = M6;


#define INTAKE_INIT_PARAMS intakePin,  intakeLimit

const MotorPin intakePin = M4;
const DIOPin intakeLimit = D8;

#define LIFT_STRING_POT_INIT_PARAMS stringPotPin

const AnalogPin stringPotPin = A0;

#define ULTRASONIC_INIT_PARAMS ultrasonicPin

const AnalogPin ultrasonicPin = A1;

namespace Config {

const int encoderTicksPerRevolution = 4096;

// Diameter of the drivetrain wheels, in inches
const double drivetrainWheelDiameter = 6;

//const double drivetrainDistancePerEncoderTick = drivetrainWheelDiameter / ((double) encoderTicksPerRevolution);
//big numbers from testing, 60 inches is the distance (5 ft) we tested with
//Units very important!!!
//const double drivetrainDistancePerEncoderTickFLBR = 60/(25000.0);
//const double drivetrainDistancePerEncoderTickFRBL = 60/(30000.0);
const double drivetrainDistancePerEncoderTick = (120/(54475.0/2.0));

const unsigned char encoderReversalMap = (char) 0b0101;

const double drivetrainEncoderTargetPositionTolerance = 1;

const Encoder::EncodingType drivetrainEncodingType = Encoder::EncodingType::k2X;

};

#endif /* Config_H */

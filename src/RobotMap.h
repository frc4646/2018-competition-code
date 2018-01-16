#ifndef ROBOTMAP_H
#define ROBOTMAP_H

#include "PinEnums.h"

/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */

// For example to map the left and right motors, you could define the
// following variables to use with your drivetrain subsystem.
// constexpr int LEFTMOTOR = 1;
// constexpr int RIGHTMOTOR = 2;

// If you are using multiple modules, make sure to define both the port
// number and the module. For example you with a rangefinder:
// constexpr int RANGE_FINDER_PORT = 1;
// constexpr int RANGE_FINDER_MODULE = 1;

// BEGIN mecanum
constexpr MotorPin frontLeft = M0;
constexpr MotorPin frontRight = M1;
constexpr MotorPin backLeft = M2;
constexpr MotorPin backRight = M3;

// END mecanum

#endif  // ROBOTMAP_H

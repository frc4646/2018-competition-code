#include "IDriveTrain.h"
#include <Commands/Subsystem.h>

using namespace loop;

IDriveTrain::IDriveTrain(std::string name) : Subsystem(name), gyro() {
	gyro.Calibrate();
}

double IDriveTrain::GetAngle() {
	return gyro.GetAngle();
}

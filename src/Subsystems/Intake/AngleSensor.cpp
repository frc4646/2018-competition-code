#include "AngleSensor.h"
#include <RobotMap.h>

AngleSensor::AngleSensor(int pin) : Subsystem("Intake"), AngleSensorPin(pin) {
	m = (MinAngle - MaxAngle) / (double)(MinValue - MaxValue);
		b = MinAngle - ((MinValue)*(m));

}

void AngleSensor::InitDefaultCommand() {
}

double AngleSensor::GetAngle(){
	double angle;

	int value = AngleSensorPin.GetValue();

	angle = ((m)*(value)) + b;

	return angle;
}
// Put methods for controlling this subsystem
// here. Call these from Commands.

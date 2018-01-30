#include "AngleSensor.h"
#include <RobotMap.h>

AngleSensor::AngleSensor(int pin) : Subsystem("Intake"), AngleSensorPin(pin) {

}

void AngleSensor::InitDefaultCommand() {
}

double AngleSensor::GetAngle(){
	double angle;
	double m;
	double b;

	int value = AngleSensorPin.GetValue();

	m = (MinAngle - MaxAngle) / (double)(MinValue - MaxValue);
	b = MinAngle - ((MinValue)*(m));
	angle = ((m)*(value)) + b;

	return angle;
}
// Put methods for controlling this subsystem
// here. Call these from Commands.

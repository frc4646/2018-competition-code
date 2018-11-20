#include <Subsystems/Lift/UltraSonic.h>
#include <RobotMap.h>
#include <frc/WPILib.h>
#include <PinEnums.h>

UltraSonic::UltraSonic(int pin) : Subsystem("Lift"), UltraSonicPin(pin) {

}

void UltraSonic::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

double UltraSonic::GetVoltage() {
	return UltraSonicPin.GetVoltage();
}

int UltraSonic::GetCounts(){
	return UltraSonicPin.GetValue();
}

double UltraSonic::GetDistance(){
	int counts = GetCounts();
	double distanceIntoRobot = 100; //TO DO, in mm

	//5 is from data sheet: 1 count = 5 mm
	//data sheet: https://www.maxbotix.com/documents/HRLV-MaxSonar-EZ_Datasheet.pdf
	//will return distance in mm
	return ((counts*5) - distanceIntoRobot);
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

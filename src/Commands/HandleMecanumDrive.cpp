#include "HandleMecanumDrive.h"
#include <LOOP/IDriveTrain.h>

using namespace loop;

HandleMecanumDrive::HandleMecanumDrive() : CommandBase("HandleDrive"), joyDB(0.1), joytar(false) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires((frc::Subsystem*) drivetrain.get());
}

// Called just before this Command runs the first time
void HandleMecanumDrive::Initialize() {
	frc::SmartDashboard::PutNumber("IC", 0);
	frc::SmartDashboard::PutNumber("P", defaultP);
	frc::SmartDashboard::PutNumber("Max Command", defaultMaxCommand);
	frc::SmartDashboard::PutNumber("Min Command", defaultMinCommand);
	frc::SmartDashboard::PutNumber("Delta Degree", deltaDegree);
	frc::SmartDashboard::PutBoolean("Heading Targeting", false);
	frc::SmartDashboard::PutNumber("Target", 0);
	frc::SmartDashboard::PutBoolean("Joystick Targeting Control", true);
	frc::SmartDashboard::PutNumber("Joystick Deadband", defaultJoyDB);
}

// Called repeatedly when this Command is scheduled to run

void HandleMecanumDrive::Execute() {
	//build drive data
	SDriveData driveData;
	driveData.cartX = oi->GetMechanismX();
	driveData.cartY = oi->GetMechanismY();
	driveData.cartR = oi->GetLeftJoystickX();

	//tar = frc::SmartDashboard::GetNumber("Target", 0);
	/*
	frc::SmartDashboard::PutNumber("Gyro heading", drivetrain->GetAngle());
	if (trackTarget) {
		driveData.cartR = std::max(std::min(frc::SmartDashboard::GetNumber("P", 0) * (drivetrain->GetAngle() - target), frc::SmartDashboard::GetNumber("IC", 0)), -frc::SmartDashboard::GetNumber("IC", 0));
		frc::SmartDashboard::PutNumber("CartR", driveData.cartR);
		frc::SmartDashboard::PutNumber("Err", (drivetrain->GetAngle() - target));
	*/
	//get more values from SD
	drivetrain->EnableTracking(frc::SmartDashboard::GetBoolean("Heading Targeting", false));
	joytar = frc::SmartDashboard::GetBoolean("Joystick Targeting Control", false);
	joyDB = frc::SmartDashboard::GetNumber("Joystick Deadband", defaultJoyDB);
	drivetrain->TrackAngle(frc::SmartDashboard::GetNumber("Target", 0));

	//deadband rotation joystick and change error variable if necessary
	if ((oi->GetLeftJoystickX() > joyDB || oi->GetLeftJoystickX() < -joyDB) && joytar){
		/*
		if (oi->GetLeftJoystickX()>0){
			tar -= (oi->GetLeftJoystickX() * ((4.0)/(1-joyDB)));
		}
		else{
			tar -= (oi->GetLeftJoystickX() * ((4.0)/(1+joyDB)));
		}
		*/
		tar -= (oi->GetLeftJoystickX() * ((3.0)/(1+joyDB)));
		// * 4 is for 180 degree rotation per second.
	}

	drivetrain->Drive(driveData);
}

// Make this return true when this Command no longer needs to run execute()
bool HandleMecanumDrive::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void HandleMecanumDrive::End() {
	drivetrain->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void HandleMecanumDrive::Interrupted() {
	End();
}

/*void HandleMecanumDrive::ShouldRunTargeting(bool enabled) {
	HandleMecanumDrive::tarHeadingMode = enabled;
}

bool HandleMecanumDrive::IsTargeting() {
	return HandleMecanumDrive::tarHeadingMode;
}

void HandleMecanumDrive::SetTarget(float target) {
	HandleMecanumDrive::tar = target;
}*/

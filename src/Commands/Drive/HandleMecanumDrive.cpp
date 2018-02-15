#include "HandleMecanumDrive.h"
#include <LOOP/IDriveTrain.h>
#include <config.h>
#include <iostream>

using namespace loop;
#if (DRIVETRAIN == MecanumDriveTrain)
HandleMecanumDrive::HandleMecanumDrive() : CommandBase("HandleDrive"), joyDB(0.1), joytar(false) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires((frc::Subsystem*) drivetrain.get());
	frc::SmartDashboard::PutNumber("Joystick Deadband", defaultJoyDB);
}

// Called just before this Command runs the first time
void HandleMecanumDrive::Initialize() {
	//gyro.Reset();
}

// Called repeatedly when this Command is scheduled to run

void HandleMecanumDrive::Execute() {
	//build drive data
	SDriveData driveData;
	driveData.cartX = oi->GetRightJoystickX();
	driveData.cartY = oi->GetRightJoystickY();
	driveData.cartR = oi->GetLeftJoystickX();

	//get more values from SD
	drivetrain->EnableTracking(frc::SmartDashboard::GetBoolean("Heading Targeting", false));
	joytar = frc::SmartDashboard::GetBoolean("Joystick Targeting Control", false);
	joyDB = frc::SmartDashboard::GetNumber("Joystick Deadband", defaultJoyDB);
	double target = frc::SmartDashboard::GetNumber("Target", 0);

	//deadband rotation joystick and change error variable if necessary
	if ((oi->GetLeftJoystickX() > joyDB || oi->GetLeftJoystickX() < -joyDB) && joytar){
		target -= (oi->GetLeftJoystickX() * ((3.0)/(1+joyDB)));
		// * 4 is for 180 degree rotation per second.
		//Only update these numbers if there has been a change
		drivetrain->SetAngleTrackingTarget(target);
		frc::SmartDashboard::PutNumber("Target", target);
	}

	// When setting driveData, multiply it by the appropriate throttle axis on each of the joysticks so we can
	// set specific speeds.
	driveData.cartX = (driveData.cartX*(oi->GetRightJoystickThrottle()*-1));
	driveData.cartY = (driveData.cartY*(oi->GetRightJoystickThrottle()*-1));
	driveData.cartR = (driveData.cartR*(oi->GetLeftJoystickThrottle()*-1));
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
#endif


#include "HandleMecanumDrive.h"

HandleMecanumDrive::HandleMecanumDrive() : CommandBase("HandleDrive"), tarHeadingMode(true), tar(0), gyro() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(drivetrain.get());
	gyro.Calibrate();
}

// Called just before this Command runs the first time
void HandleMecanumDrive::Initialize() {
	gyro.Reset();
	frc::SmartDashboard::PutNumber("P", defaultP);
	frc::SmartDashboard::PutNumber("Max Command", defaultMaxCommand);
	frc::SmartDashboard::PutNumber("Min Command", defaultMinCommand);
	frc::SmartDashboard::PutNumber("Delta Degree", deltaDegree);
	frc::SmartDashboard::PutBoolean("Heading Targeting", false);
	frc::SmartDashboard::PutNumber("Target", 0);
	frc::SmartDashboard::PutNumber("Joystick Targeting Control", false);
	frc::SmartDashboard::PutNumber("Joystick Deadband", defaultJoyDB);
}

// Called repeatedly when this Command is scheduled to run

void HandleMecanumDrive::Execute() {

	//build drive data
	SDriveData driveData;
	driveData.cartX = oi->GetMechanismX();
	driveData.cartY = oi->GetMechanismY();
	driveData.cartR = oi->GetLeftJoystickX();

	//get heading targeting values
	tarHeadingMode = frc::SmartDashboard::GetBoolean("Heading Targeting", false);
	tar = frc::SmartDashboard::GetNumber("Target", 0);
	joytar = frc::SmartDashboard::GetBoolean("Joystick Targeting Control", false);
	joyDB = frc::SmartDashboard::GetNumber("Joystick Deadband", defaultJoyDB);

	//put gyro on dashboard
	frc::SmartDashboard::PutNumber("Gyro heading", gyro.GetAngle());

	//deadband rotation joystick and change error variable if necessary
	if ((oi->GetLeftJoystickX() > joyDB || oi->GetLeftJoystickX() < -joyDB) && joytar && (tar < 20 && tar > -20)){
		tar += oi->GetLeftJoystickX();
	}

	//if targeting is on, run P loop math
	if (tarHeadingMode) {
		double p = frc::SmartDashboard::GetNumber("P", defaultP);
		double maxCommand = frc::SmartDashboard::GetNumber("Max Command", defaultMaxCommand);
		double minCommand = frc::SmartDashboard::GetNumber("Min Command", defaultMinCommand);
		double delta = frc::SmartDashboard::GetNumber("Delta Degree", deltaDegree);
		double error = (gyro.GetAngle() - tar);
		double motorCommand;

		if (std::abs(error) < delta){
			//close enough to target so turn off command
			motorCommand = 0;
		}
		else{
			//need to move the robot
			motorCommand = p * error;
			if (motorCommand > maxCommand){
				motorCommand = maxCommand;
			}
			else if ((motorCommand < minCommand) && (motorCommand > 0)){
				motorCommand = minCommand;
			}
			else if((motorCommand > -minCommand) && (motorCommand < 0)){
				motorCommand = -minCommand;
			}
			else if (motorCommand < -maxCommand){
				motorCommand = -maxCommand;
			}
		}

		driveData.cartR = motorCommand;
		frc::SmartDashboard::PutNumber("CartR", driveData.cartR);
		frc::SmartDashboard::PutNumber("Err", error);
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

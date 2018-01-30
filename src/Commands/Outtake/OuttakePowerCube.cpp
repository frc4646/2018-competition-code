<<<<<<< HEAD
#include "OuttakePowerCube.h"

OuttakePowerCube::OuttakePowerCube() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(intake.get());
}

// Called just before this Command runs the first time
void OuttakePowerCube::Initialize() {
	intake->SetIntakePower(-1);
}

// Called repeatedly when this Command is scheduled to run
void OuttakePowerCube::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool OuttakePowerCube::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void OuttakePowerCube::End() {
	intake->SetIntakePower(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void OuttakePowerCube::Interrupted() {
	End();
}
=======
#include "OuttakePowerCube.h"

OuttakePowerCube::OuttakePowerCube() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void OuttakePowerCube::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void OuttakePowerCube::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool OuttakePowerCube::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void OuttakePowerCube::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void OuttakePowerCube::Interrupted() {

}
>>>>>>> 7c4ef7586961181d848fb171a63752b73ecdac32

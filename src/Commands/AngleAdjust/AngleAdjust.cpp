<<<<<<< HEAD:src/Commands/AngleAdjust/AngleAdjust.cpp
#include "AngleAdjust.h"

AngleAdjust::AngleAdjust(double angle) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(intake.get());
	a = angle;
}

// Called just before this Command runs the first time
void AngleAdjust::Initialize() {
	intake->SetIntakeAngle(a);
}

// Called repeatedly when this Command is scheduled to run
void AngleAdjust::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool AngleAdjust::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void AngleAdjust::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AngleAdjust::Interrupted() {

}
=======
#include "OuttakeAngleAdjust.h"

OuttakeAngleAdjust::OuttakeAngleAdjust() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void OuttakeAngleAdjust::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void OuttakeAngleAdjust::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool OuttakeAngleAdjust::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void OuttakeAngleAdjust::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void OuttakeAngleAdjust::Interrupted() {

}
>>>>>>> 7c4ef7586961181d848fb171a63752b73ecdac32:src/Commands/Outtake/OuttakeAngleAdjust.cpp

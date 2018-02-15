/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "IntakePowerCube.h"
#include "Subsystems/Intake/IntakeControl.h"

IntakePowerCube::IntakePowerCube() : CommandBase("IntakePowerCube") {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(intake.get());
}

// Called just before this Command runs the first time
void IntakePowerCube::Initialize() {
	intake->SetIntakePower(1);
}

// Called repeatedly when this Command is scheduled to run
void IntakePowerCube::Execute() {
	intake->SetIntakePower(1);
}

// Make this return true when this Command no longer needs to run execute()
bool IntakePowerCube::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void IntakePowerCube::End() {
	intake->SetIntakePower(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void IntakePowerCube::Interrupted() {
	End();
}

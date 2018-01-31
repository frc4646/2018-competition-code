#include "Idle.h"
#include <cstdarg>
#include <functional>

using namespace loop;

Idle::Idle(int numRequires, ...) : Command("Idle") {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	va_list arguments;
	va_start(arguments, numRequires);
	for (int i = 0; i < numRequires; i++) {
		Requires(va_arg(arguments, frc::Subsystem*));
	}
	va_end(arguments);
}

// Called just before this Command runs the first time
void Idle::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void Idle::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool Idle::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void Idle::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Idle::Interrupted() {

}

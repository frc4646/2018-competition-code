#include "Binding.h"
#include <cstdarg>
#include <functional>

using namespace loop;

Binding::Binding(std::function<void (void)> init, std::function<void (void)> exec, std::function<void (void)> end, int numRequires, ...) : Command("Binding"){
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	initialise = init;
	execute = exec;
	endOrInterrupt = end;
	va_list arguments;
	va_start(arguments, numRequires);
	for (int i = 0; i < numRequires; i++) {
		Requires(va_arg(arguments, frc::Subsystem*));
	}
	va_end(arguments);
}

// Called just before this Command runs the first time
void Binding::Initialize() {
	initialise();
}

// Called repeatedly when this Command is scheduled to run
void Binding::Execute() {
	execute();
}

// Make this return true when this Command no longer needs to run execute()
bool Binding::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void Binding::End() {
	endOrInterrupt();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Binding::Interrupted() {
	End();
}


#include "CommandBase.h"

#include <Commands/Scheduler.h>
#include <Subsystems/Drivetrain/MecanumDriveTrain.h>
#include <Subsystems/Lift/LiftControl.h>
#include <Subsystems/Intake/IntakeControl.h>

#include "PinEnums.h"
#include "Config.h"

// Initialize a single static instance of all of your subsystems. The following
// line should be repeated for each subsystem in the project.
std::unique_ptr<DRIVETRAIN> CommandBase::drivetrain = NULL;
std::unique_ptr<LiftControl> CommandBase::lift = NULL;
std::unique_ptr<IntakeControl> CommandBase::intake = NULL;

std::unique_ptr<OI> CommandBase::oi = std::make_unique<OI>();

CommandBase::CommandBase(const std::string &name) :
		frc::Command(name) {

}

void CommandBase::init() {
	drivetrain.reset(new DRIVETRAIN(DRIVETRAIN_INIT_PARAMS));
	lift.reset(new LiftControl(LIFT_INIT_PARAMS));
	intake.reset(new IntakeControl(INTAKE_INIT_PARAMS));
}

#include "CommandBase.h"

#include <Commands/Scheduler.h>
#include <Subsystems/Drivetrain/MecanumDriveTrain.h>

#include "PinEnums.h"
#include "Config.h"

// Initialize a single static instance of all of your subsystems. The following
// line should be repeated for each subsystem in the project.
std::unique_ptr<DRIVETRAIN> CommandBase::drivetrain = NULL;

std::unique_ptr<OI> CommandBase::oi = std::make_unique<OI>();

CommandBase::CommandBase(const std::string &name) :
		frc::Command(name) {

}

void CommandBase::init() {
	drivetrain.reset(new DRIVETRAIN(DRIVETRAIN_INIT_PARAMS));
}


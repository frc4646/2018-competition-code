
#ifndef COMMAND_BASE_H
#define COMMAND_BASE_H

#include <memory>
#include <string>

#include <Commands/Command.h>

#include "OI.h"
#include "PinEnums.h"
#include "Config.h"
#include "Subsystems/Drivetrain/MecanumDriveTrain.h"
#include "Subsystems/Lift/LiftControl.h"
#include "Subsystems/Intake/IntakeControl.h"
#include "Subsystems/Lift/LiftStringPot.h"
#include "Subsystems/Lift/UltraSonic.h"

/**
 * The base for all commands. All atomic commands should subclass CommandBase.
 * CommandBase stores creates and stores each control system. To access a
 * subsystem elsewhere in your code in your code use
 * CommandBase::exampleSubsystem
 */
class CommandBase: public frc::Command {
public:
	CommandBase(const std::string& name);
	CommandBase() = default;

	static void init();

	// Create a single static instance of all of your subsystems
	static std::unique_ptr<DRIVETRAIN> drivetrain;
	static std::unique_ptr<LiftControl> lift;
	static std::unique_ptr<IntakeControl> intake;
	static std::unique_ptr<LiftStringPot> liftStringPot;
	static std::unique_ptr<UltraSonic> ultrasonic;
	static std::unique_ptr<OI> oi;
};

#endif  // COMMAND_BASE_H


/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include <Commands/Command.h>
#include <Commands/Scheduler.h>
#include <LiveWindow/LiveWindow.h>
#include <SmartDashboard/SendableChooser.h>
#include <SmartDashboard/SmartDashboard.h>
#include <TimedRobot.h>

#include "Commands/ExampleCommand.h"
#include "Commands/MyAutoCommand.h"
#include "AutoCommands/AutonomousCommands/RobotCenterSwitchLeft.h"
#include "AutoCommands/AutonomousCommands/RobotCenterSwitchRight.h"
#include "AutoCommands/AutonomousCommands/RobotCross.h"
#include "AutoCommands/AutonomousCommands/RobotLeftScaleRight.h"
#include "AutoCommands/AutonomousCommands/RobotRightScaleLeft.h"
#include "AutoCommands/AutonomousCommands/RobotScaleFront.h"
#include "CommandBase.h"

#include "Config.h"

#include <map>

using namespace loop;

class Robot : public frc::TimedRobot {
public:
	void RobotInit() override {
		CommandBase::init();
		m_chooser.AddDefault("Default Auto", &m_defaultAuto);
		m_chooser.AddObject("My Auto", &m_myAuto);
		frc::SmartDashboard::PutData("Auto Modes", &m_chooser);
		frc::SmartDashboard::PutString("Drive train", "DRIVETRAIN");
		m_location_chooser.AddDefault("Center", Location::CENTER);
		m_location_chooser.AddObject("Left", Location::LEFT);
		m_location_chooser.AddObject("Right", Location::RIGHT);
		frc::SmartDashboard::PutData("Robot location", &m_location_chooser);
		//autoLut.insert("LLL", rlscl);
		autoLut.insert(std::pair<std::string, frc::Command>("LLR", rlscr));
		autoLut.insert(std::pair<std::string, frc::Command>("LRR", rlscr));
		autoLut.insert(std::pair<std::string, frc::Command>("LRL", rscf));
		autoLut.insert(std::pair<std::string, frc::Command>("RLL", rrscl));
		autoLut.insert(std::pair<std::string, frc::Command>("RLR", rscf));
		autoLut.insert(std::pair<std::string, frc::Command>("RRR", rscf));
		autoLut.insert(std::pair<std::string, frc::Command>("RRL", rrscl));
		autoLut.insert(std::pair<std::string, frc::Command>("CLL", rcswl));
		autoLut.insert(std::pair<std::string, frc::Command>("CLR", rcswr));
		autoLut.insert(std::pair<std::string, frc::Command>("CRR", rcswr));
		autoLut.insert(std::pair<std::string, frc::Command>("CRL", rcswl));
	}

	/**
	 * This function is called once each time the robot enters Disabled
	 * mode.
	 * You can use it to reset any subsystem information you want to clear
	 * when
	 * the robot is disabled.
	 */
	void DisabledInit() override {}

	void DisabledPeriodic() override {
		frc::Scheduler::GetInstance()->Run();
	}

	/**
	 * This autonomous (along with the chooser code above) shows how to
	 * select
	 * between different autonomous modes using the dashboard. The sendable
	 * chooser code works with the Java SmartDashboard. If you prefer the
	 * LabVIEW Dashboard, remove all of the chooser code and uncomment the
	 * GetString code to get the auto name from the text box below the Gyro.
	 *
	 * You can add additional auto modes by adding additional commands to
	 * the
	 * chooser code above (like the commented example) or additional
	 * comparisons
	 * to the if-else structure below with additional strings & commands.
	 */
	void AutonomousInit() override {
		std::string robotLocation = frc::SmartDashboard::GetString("Robot location", "Center");
		if (robotLocation == "Left") {
			loc = Location::LEFT;
		} else if (robotLocation == "Center") {
			loc = Location::CENTER;
		} else {
			loc = Location::RIGHT;
		}

		m_autonomousCommand = autoLut[robotLocation[0] + frc::DriverStation::GetInstance().GetGameSpecificMessage()[0] + frc::DriverStation::GetInstance().GetGameSpecificMessage()[1]];
		m_autonomousCommand->Start();
		//TODO MLL - Fgure out which autonomus commands we want to run!
	}

	void AutonomousPeriodic() override {
		frc::Scheduler::GetInstance()->Run();
	}

	void TeleopInit() override {
		// This makes sure that the autonomous stops running when
		// teleop starts running. If you want the autonomous to
		// continue until interrupted by another command, remove
		// this line or comment it out.
		if (m_autonomousCommand != nullptr) {
			m_autonomousCommand->Cancel();
			m_autonomousCommand = nullptr;
		}
	}

	void TeleopPeriodic() override { frc::Scheduler::GetInstance()->Run(); }

	void TestPeriodic() override {}

private:
	enum Location {
		LEFT,
		CENTER,
		RIGHT
	};
	Location loc;
	std::map<std::string, frc::Command> autoLut;
	// Have it null by default so that if testing teleop it
	// doesn't have undefined behavior and potentially crash.
	frc::Command* m_autonomousCommand = nullptr;
	ExampleCommand m_defaultAuto;
	MyAutoCommand m_myAuto;
	RobotCenterSwitchLeft rcswl;
	RobotCenterSwitchRight rcswr;
	RobotCross rcr;
	RobotLeftScaleRight rlscr;
	RobotRightScaleLeft rrscl;
	RobotScaleFront rscf;
	frc::SendableChooser<frc::Command*> m_chooser;
	frc::SendableChooser<Location> m_location_chooser;
};

START_ROBOT_CLASS(Robot)

/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include <AutoCommands/AutonomousCommands/DriveForTime.h>
#include <Commands/Command.h>
#include <Commands/Scheduler.h>
#include <LiveWindow/LiveWindow.h>
#include <SmartDashboard/SendableChooser.h>
#include <SmartDashboard/SmartDashboard.h>
#include <TimedRobot.h>

#include "Commands/ExampleCommand.h"
#include "Commands/MyAutoCommand.h"
#include "AutoCommands/AutonomousCommands/RobotLeftScaleRight.h"
#include "AutoCommands/AutonomousCommands/RobotRightScaleLeft.h"
#include "AutoCommands/AutonomousCommands/RobotScaleFront.h"
#include "AutoCommands/AutonomousCommands/Kickstand.h"
#include "AutoCommands/AutonomousCommands/DriveAndSwitch.h"
#include "AutoCommands/AutonomousCommands/DriveAndScale.h"
#include "CommandBase.h"

#include "Config.h"

#include <map>
#include <utility>
#include <string>
#include <iostream>

using namespace loop;

class Robot : public frc::TimedRobot {
public:
	enum Location {
		LEFT,
		CENTER,
		RIGHT
	};
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
		if (!frc::Preferences::GetInstance()->ContainsKey("intake-power")){
			frc::Preferences::GetInstance()->PutDouble("intake-power", 0.3);
		}
		if (!frc::Preferences::GetInstance()->ContainsKey("outtake-power")){
			frc::Preferences::GetInstance()->PutDouble("outtake-power", 0.5);
		}
		if (!frc::Preferences::GetInstance()->ContainsKey("lift-hold-command")){
			frc::Preferences::GetInstance()->PutDouble("lift-hold-command", 0.15);
		}
		//autoLut.insert("LLL", rlscl);
		//autoLut["LLR"] = rlscr;
		/*rlscr = *(new RobotLeftScaleRight());
		rscf = *(new RobotScaleFront());
		rrscl = *(new RobotRightScaleLeft());
		rcswl = *(new RobotCenterSwitchLeft());
		rcswr();
		rcr();
		autoLut.insert(std::pair<std::string, frc::Command*>(std::string("LLR"), &rlscr));
		autoLut.insert(std::pair<std::string, frc::Command*>(std::string("LRR"), &rlscr));
		autoLut.insert(std::pair<std::string, frc::Command*>(std::string("LRL"), &rscf));
		autoLut.insert(std::pair<std::string, frc::Command*>(std::string("RLL"), &rrscl));
		autoLut.insert(std::pair<std::string, frc::Command*>(std::string("RLR"), &rscf));
		autoLut.insert(std::pair<std::string, frc::Command*>(std::string("RRR"), &rscf));
		autoLut.insert(std::pair<std::string, frc::Command*>(std::string("RRL"), &rrscl));
		autoLut.insert(std::pair<std::string, frc::Command*>(std::string("CLL"), &rcswl));
		autoLut.insert(std::pair<std::string, frc::Command*>(std::string("CLR"), &rcswr));
		autoLut.insert(std::pair<std::string, frc::Command*>(std::string("CRR"), &rcswr));
		autoLut.insert(std::pair<std::string, frc::Command*>(std::string("CRL"), &rcswl));*/
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
		loc = m_location_chooser.GetSelected();
		/*if (robotLocation == "Left") {
			m_autonomousCommand = new DriveForwardForTime(3);
		} else if (robotLocation == "Center") {
			loc = Location::CENTER;
			m_autonomousCommand = new DriveAndSwitch();
		} else {
			loc = Location::RIGHT;
			m_autonomousCommand = new DriveForwardForTime(3);
		}*/
		char switchLoc = frc::DriverStation::GetInstance().GetGameSpecificMessage()[0];
		char scaleLoc = frc::DriverStation::GetInstance().GetGameSpecificMessage()[1];
		switch (loc) {
			case Location::LEFT:
				/*if (scaleLoc == 'L'){
					m_autonomousCommand = new DriveAndScale(true, false, false);
				}
				else if (switchLoc == 'L'){
					m_autonomousCommand = new DriveAndScale(false, true, false);
				}
				else{
					m_autonomousCommand = new DriveAndScale(false, false, false);
				}
				break;*/

			case Location::RIGHT:
				m_autonomousCommand = new DriveForTime(3, false);
				/*
				std::cout << "Running DriveForwardForTime" << std::endl;
				break;
				if (scaleLoc == 'R'){
					m_autonomousCommand = new DriveAndScale(true, false, true);
				}
				else if (switchLoc == 'R'){
					m_autonomousCommand = new DriveAndScale(false, true, true);
				}
				else{
					m_autonomousCommand = new DriveAndScale(false, false, true);
				}*/
				break;
			case Location::CENTER:
				double sideDist;
				if (switchLoc == 'L'){
					sideDist = -70;
				}
				else{
					sideDist = 70;
				}
				m_autonomousCommand = new DriveAndSwitch(sideDist);
				std::cout << "Running Switch Auto" << std::endl;
				break;
		}

		//m_autonomousCommand = autoLut[robotLocation.substr(0, 1) + frc::DriverStation::GetInstance().GetGameSpecificMessage().substr(0, 2)];
		//m_autonomousCommand->Start();
		//TODO MLL - Fgure out which autonomus commands we want to run!
		//new RobotCross();
		//m_autonomousCommand = new DriveForwardForTime(3);
		m_autonomousCommand->Start();
	}

	void AutonomousPeriodic() override {
		frc::Scheduler::GetInstance()->Run();
		if (m_autonomousCommand != nullptr) {
			if (!m_autonomousCommand->IsRunning()) {
				CommandBase::drivetrain->EnableAngleHold(false);
			}
		}
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
		CommandBase::drivetrain->EnableAngleHold(true);
	}

	void TeleopPeriodic() override { frc::Scheduler::GetInstance()->Run(); }

	void TestPeriodic() override {}

private:
	Location loc;
	std::map<std::string, frc::Command*> autoLut;
	// Have it null by default so that if testing teleop it
	// doesn't have undefined behavior and potentially crash.
	frc::Command* m_autonomousCommand = nullptr;
	ExampleCommand m_defaultAuto;
	MyAutoCommand m_myAuto;
//	RobotCenterSwitchLeft rcswl;
//	RobotCenterSwitchRight rcswr;
//	RobotCross rcr;
//	RobotLeftScaleRight rlscr;
//	RobotRightScaleLeft rrscl;
//	RobotScaleFront rscf;
	frc::SendableChooser<frc::Command*> m_chooser;
	frc::SendableChooser<Location> m_location_chooser;
};

START_ROBOT_CLASS(Robot)

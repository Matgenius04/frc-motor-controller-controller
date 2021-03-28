// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "Robot.h"
#include <frc/shuffleboard/Shuffleboard.h>
// #include <frc/shuffleboard/ShuffleboardTab.h>
#include "Constants.h"
#include "networktables/NetworkTable.h"
#include <wpi/StringMap.h>

// TODO: bruhhhhhhh
// #include <frc/Filesystem.h>

// #include <wpi/Path.h>

// #include <wpi/SmallString.h>

// #include <wpi/json.h>

// #include <frc/trajectory/TrajectoryUtil.h>

// #include <wpi/raw_istream.h>

// using namespace wpi;

void Robot::RobotInit()
{
  // using namespace frc;
  // frc::filesystem::GetDeployDirectory(deployDirectory);
  // frc::Trajectory trajectory = frc::TrajectoryUtil::FromPathweaverJson(deployDirectory);
  // I don't know why but the type definition is unknown here? so need an frc:: for ShufflebaordTab
  // ShuffleboardTab motorControllerTab = Shuffleboard::GetTab(wpi::StringRef{tabName});
}

/**
 * This function is called every robot packet, no matter the mode. Use
 * this for items like diagnostics that you want ran during disabled,
 * autonomous, teleoperated and test.
 *
 * <p> This runs after the mode specific periodic functions, but before
 * LiveWindow and SmartDashboard integrated updating.
 */
void Robot::RobotPeriodic() {}

/**
 * This autonomous (along with the chooser code above) shows how to select
 * between different autonomous modes using the dashboard. The sendable chooser
 * code works with the Java SmartDashboard. If you prefer the LabVIEW Dashboard,
 * remove all of the chooser code and uncomment the GetString line to get the
 * auto name from the text box below the Gyro.
 *
 * You can add additional auto modes by adding additional comparisons to the
 * if-else structure below with additional strings. If using the SendableChooser
 * make sure to add them to the chooser code above as well.
 */
void Robot::AutonomousInit()
{

}

void Robot::AutonomousPeriodic()
{

}

void Robot::TeleopInit() {}

void Robot::TeleopPeriodic() {}

void Robot::DisabledInit() {}

void Robot::DisabledPeriodic() {}

// Where all the test code can be run
void Robot::TestInit()
{
  // TODO: implement
  // wpi::from_json() = wpi::sys::path::append(deployDirectory, "MotorController.json");
  // std::error_code error_code;

  // wpi::SmallString<128> deployDirectory;
  // wpi::raw_fd_istream input{path.toStringRef(deployDirectory), error_code};
  // if (error_code) {
  //   throw std::runtime_error(("Cannot open file: " + path).str());
  // }

  // wpi::json json;
  // input >> json;

  // return json.get<std::vector>

  // init motor control sliders
}

void Robot::TestPeriodic()
{
  using namespace frc;
  // loop over all the motors?
  // ShuffleboardTab &tab = Shuffleboard::GetTab(tabName);
  for (auto motor : loadedMotors.GetMotorControllerInfoVector()) {
    printf("%g", motor.GetMotorControlSliderValue());

  }
}

#ifndef RUNNING_FRC_TESTS
int main()
{
  return frc::StartRobot<Robot>();
}
#endif

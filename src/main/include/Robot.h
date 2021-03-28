// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <string>
#include "Constants.h"

#include <frc/TimedRobot.h>
#include <frc/smartdashboard/SendableChooser.h>

class Robot : public frc::TimedRobot
{
public:
  void RobotInit() override;
  void RobotPeriodic() override;
  void AutonomousInit() override;
  void AutonomousPeriodic() override;
  void TeleopInit() override;
  void TeleopPeriodic() override;
  void DisabledInit() override;
  void DisabledPeriodic() override;
  void TestInit() override;
  void TestPeriodic() override;
  // TODO: fix
  // wpi::json ParseJson(path);

private:
  // TODO: implement
  custom2498::LoadedMotors loadedMotors{
      std::vector<custom2498::MotorControllerInfo> {
          custom2498::MotorControllerInfo {
              "Green",
              5,
              custom2498::MotorType::SparkMax
          },
          custom2498::MotorControllerInfo {
              "Intake Tunnel",
              6,
              custom2498::MotorType::SparkMax
          }
      }
  };
};

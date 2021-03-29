// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <string>
#include "Constants.h"
#
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
  custom2498::LoadedMotors loadedMotors {
      std::vector<custom2498::MotorControllerInfo> {
        custom2498::MotorControllerInfo {
              "Front Right",
              1,
              custom2498::MotorControllerType::SparkMax
          },
          custom2498::MotorControllerInfo {
              "Front Left",
              2,
              custom2498::MotorControllerType::SparkMax
          },
          custom2498::MotorControllerInfo {
              "Rear Right",
              3,
              custom2498::MotorControllerType::SparkMax
          },
          custom2498::MotorControllerInfo {
              "Rear Left",
              4,
              custom2498::MotorControllerType::SparkMax
          },
          custom2498::MotorControllerInfo {
              "Green",
              5,
              custom2498::MotorControllerType::SparkMax
          },
          custom2498::MotorControllerInfo {
              "Intake Tunnel",
              6,
              custom2498::MotorControllerType::SparkMax
          }
      },
      true,
      1,2,3,4
  };
  // Here you can just edit the code below to enable mecanum drive


};

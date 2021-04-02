// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "Robot.h"

void Robot::RobotInit() {}
void Robot::RobotPeriodic() {}

void Robot::AutonomousInit() {}
void Robot::AutonomousPeriodic() {}

void Robot::TeleopInit() {}
void Robot::TeleopPeriodic() {}

void Robot::DisabledInit() {}
void Robot::DisabledPeriodic() {}

void Robot::TestInit()
{
  dashGui.AddSlider("FR Mec"            , guiTab, new custom2498::SparkMAX(1, rev::CANSparkMax::MotorType::kBrushless));
  dashGui.AddSlider("FL Mec"            , guiTab, new custom2498::SparkMAX(2, rev::CANSparkMax::MotorType::kBrushless));
  dashGui.AddSlider("RR Mec"            , guiTab, new custom2498::SparkMAX(3, rev::CANSparkMax::MotorType::kBrushless));
  dashGui.AddSlider("RL Mec"            , guiTab, new custom2498::SparkMAX(4, rev::CANSparkMax::MotorType::kBrushless));
  dashGui.AddSlider("Green"             , guiTab, new custom2498::SparkMAX(5, rev::CANSparkMax::MotorType::kBrushed));
  dashGui.AddSlider("Tunnel Escalator"  , guiTab, new custom2498::SparkMAX(6, rev::CANSparkMax::MotorType::kBrushed));
  dashGui.AddSlider("Shooter Motor 1"   , guiTab, new custom2498::SparkMAX(7, rev::CANSparkMax::MotorType::kBrushed));
  dashGui.AddSlider("Shooter Motor 2"   , guiTab, new custom2498::SparkMAX(8, rev::CANSparkMax::MotorType::kBrushed));
  dashGui.AddSlider("Purpule"           , guiTab, new custom2498::SparkMAX(9, rev::CANSparkMax::MotorType::kBrushed));
};

void Robot::TestPeriodic()
{
  dashGui.UpdateAll();
}

#ifndef RUNNING_FRC_TESTS
int main()
{
  return frc::StartRobot<Robot>();
}
#endif

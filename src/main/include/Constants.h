#pragma once
#include "MotorController.h"
#include "SparkMAX.h"
#include "TalonSRX.h"
#include "GUI.h"
#include "Mecanum.h"
#include <rev/CANSparkMax.h>

// Hopefully will be able to replace everything in here
// with the json hotswappable system

std::string guiTab = "Dashboard";
constexpr int  throttleChannel = 0;
constexpr int  stickChannel = 1;
constexpr int pigeonId = 0;
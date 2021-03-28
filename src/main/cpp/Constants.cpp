#include "Constants.h"
// #include <string.h>
#include <frc/shuffleboard/Shuffleboard.h>
#include "networktables/NetworkTable.h"
#include <wpi/StringMap.h>
#include "rev/CANSparkMax.h"
#include "ctre/Phoenix.h"
#define NULL nullptr

using namespace frc;
using namespace std;
using namespace nt;

// also initializes all the shuffleboard components as well
custom2498::MotorControllerInfo MotorControllerInfo(string nameParam, int can_idParam, const custom2498::MotorType MotorTypeParam)
{
    const custom2498::MotorType motorType = MotorTypeParam;
    int can_id = can_idParam;
    if (motorType == custom2498::MotorType::SparkMax) {
        rev::CANSparkMax canControllerSpark {can_idParam, rev::CANSparkMax::MotorType::kBrushed};
    } else if (motorType == custom2498::MotorType::TalonSRX) {
        ctre::phoenix::motorcontrol::can::WPI_TalonSRX canControllerTalon {can_idParam};
    }
    wpi::StringMap<std::shared_ptr<nt::Value>> properties
    {
        std::make_pair("min", nt::Value::MakeDouble(0)),
        std::make_pair("max", nt::Value::MakeDouble(1))
    };
    const NetworkTableEntry motorControlSlider = Shuffleboard::GetTab(tabName)
                                                          .Add(nameParam, 0)
                                                          .WithWidget(BuiltInWidgets{BuiltInWidgets::kNumberSlider})
                                                          .WithProperties(properties)
                                                          .GetEntry();
    
};

double custom2498::MotorControllerInfo::GetMotorControlSliderValue()
{
    return motorControlSlider.GetDouble(0.0);
};

custom2498::LoadedMotors LoadedMotors(std::vector<custom2498::MotorControllerInfo> MotorControllerInfoVector)
{
    // TODO: figure out how to use pointers instead of copying the vector like an idiot 
    std::vector<custom2498::MotorControllerInfo> MotorControllerInfoVector(MotorControllerInfoVector);
};

custom2498::LoadedMotors custom2498::LoadedMotors::FromJSON(string jsonFilename)
{
    // TODO: parse json
    // return LoadedMotors

}

std::vector<custom2498::MotorControllerInfo> custom2498::LoadedMotors::GetMotorControllerInfoVector()
{
    return MotorControllerInfoVector;
}


// void MotorControllerInfo::setMotorControlSlider(NetworkTableEntry &entry) 
// {

// };
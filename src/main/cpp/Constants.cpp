#include "Constants.h"
// #include <string.h>
#include <frc/shuffleboard/Shuffleboard.h>
#include "networktables/NetworkTable.h"
#include <wpi/StringMap.h>
#include "rev/CANSparkMax.h"
#include "frc/WPIlib.h"
#include "ctre/Phoenix.h"
// #define NULL nullptr

// using namespace frc;
// using namespace std;
// using namespace nt;
// using namespace ctre;
// using namespace rev;
// also initializes all the shuffleboard components as well

// custom2498::MotorControllerInfo 
// custom2498::MotorControllerInfo

// custom2498::MotorControllerInfo::MotorControllerInfo() {

// };
custom2498::MotorControllerInfo::MotorControllerInfo(std::string nameParam, int can_idParam, const MotorType MotorTypeParam)
{
    motorType = MotorTypeParam;
    can_id = can_idParam;
    // canControllerSpark {can_id, rev::CANSparkMax::MotorType::kBrushed};
    rev::CANSparkMax{can_id, rev::CANSparkMaxLowLevel::MotorType::kBrushed};
    // if (motorType == custom2498::MotorType::SparkMax) {
    //     // canControllerSpark = rev::CANSparkMax(can_id, rev::CANSparkMax::MotorType::kBrushed);
    //     rev::CANSparkMax canControllerSpark {can_id, rev::CANSparkMax::MotorType::kBrushed};
    // } else if (motorType == custom2498::MotorType::TalonSRX) {
    //     ctre::phoenix::motorcontrol::can::WPI_TalonSRX canControllerTalon {can_id};
    // }
    wpi::StringMap<std::shared_ptr<nt::Value>> properties{
        std::make_pair("min", nt::Value::MakeDouble(0)),
        std::make_pair("max", nt::Value::MakeDouble(1))};
    const nt::NetworkTableEntry motorControlSlider = frc::Shuffleboard::GetTab(tabName)
                                                         .Add(nameParam, 0)
                                                         .WithWidget(frc::BuiltInWidgets{frc::BuiltInWidgets::kNumberSlider})
                                                         .WithProperties(properties)
                                                         .GetEntry();
};

double custom2498::MotorControllerInfo::GetMotorControlSliderValue()
{
    return motorControlSlider.GetDouble(0.0);
};

custom2498::LoadedMotors::LoadedMotors(std::vector<MotorControllerInfo> MotorControllerInfoVector)
{
    // TODO: figure out how to use pointers instead of copying the vector like an idiot
    std::vector<MotorControllerInfo> MotorControllerInfoVector(MotorControllerInfoVector);
};

custom2498::LoadedMotors custom2498::LoadedMotors::FromJSON(std::string jsonFilename)
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
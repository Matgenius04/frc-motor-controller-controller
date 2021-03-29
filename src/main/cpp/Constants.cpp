#include "Constants.h"
// #include <string.h>
#include <frc/shuffleboard/Shuffleboard.h>
#include "networktables/NetworkTable.h"
#include <wpi/StringMap.h>
#include "rev/CANSparkMax.h"
#include "frc/WPIlib.h"
#include "ctre/Phoenix.h"
#include <frc/drive/MecanumDrive.h>
// #define NULL nullptr

// using namespace frc;
// using namespace std;
// using namespace nt;
// using namespace ctre;
// using namespace rev;
// also initializes all the shuffleboard components as well

// custom2498:Controller:MotorControllerInfo 
// custom2498::MotorControllerInfo

// custom2498::MotorControllerInfo::MotorControllerInfo() {

// };
custom2498::MotorControllerInfo::MotorControllerInfo(std::string nameParam, int can_idParam, const MotorControllerType MotorTypeParam)
{
    motorType = MotorTypeParam;
    can_id = can_idParam;
    // canControllerSpark {can_id, rev::CANSparkMax::MotorType::kBrushed};
    
    if (motorType == custom2498::MotorControllerType::SparkMax) {
        // canControllerSpark = rev::CANSparkMax(can_id, rev::CANSparkMax::MotorType::kBrushed);
        rev::CANSparkMax canControllerSparkLocal{can_id, rev::CANSparkMax::MotorType::kBrushed};
        canControllerSpark = &canControllerSparkLocal;

    } else if (motorType == custom2498::MotorControllerType::TalonSRX) {
        ctre::phoenix::motorcontrol::can::WPI_TalonSRX canControllerTalonLocal{can_id};
        canControllerTalon = &canControllerTalonLocal;
    } else {
        throw "BRUHHHH OTHER MOTOR CONTROLLERS NOT SUPPORTED";
    }
    wpi::StringMap<std::shared_ptr<nt::Value>> properties{
        std::make_pair("min", nt::Value::MakeDouble(0)),
        std::make_pair("max", nt::Value::MakeDouble(1))};
    const nt::NetworkTableEntry motorControlSlider = frc::Shuffleboard::GetTab(tabName)
                                                         .Add(nameParam, 0)
                                                         .WithWidget(frc::BuiltInWidgets{frc::BuiltInWidgets::kNumberSlider})
                                                         .WithProperties(properties)
                                                         .GetEntry();
}

void custom2498::MotorControllerInfo::UpdateMotorController()
{
    
}

double custom2498::MotorControllerInfo::GetMotorControlSliderValue()
{
    return motorControlSlider.GetDouble(0.0);
}

custom2498::LoadedMotors::LoadedMotors(std::vector<MotorControllerInfo> MotorControllerInfoVectorParam, bool robotDrive = false, int fr = -1, int fl = -1, int rr = -1, int rl = -1)
{
    // TODO: figure out how to use pointers instead of copying the vector like an idiot
    std::vector<MotorControllerInfo> MotorControllerInfoVector(MotorControllerInfoVectorParam);
    if (robotDrive == true) {
        
        // frc::MecanumDrive *mecanumDriveLocal {};
    }
}

custom2498::LoadedMotors custom2498::LoadedMotors::FromJSON(std::string jsonFilename)
{
    // TODO: parse json
    // return LoadedMotors
    // placeholder for now
    return custom2498::LoadedMotors {
      std::vector<custom2498::MotorControllerInfo> {
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
      }
  };
}

std::vector<custom2498::MotorControllerInfo> custom2498::LoadedMotors::GetMotorControllerInfoVector()
{
    return MotorControllerInfoVector;
}

// void MotorControllerInfo::setMotorControlSlider(NetworkTableEntry &entry)
// {

// };
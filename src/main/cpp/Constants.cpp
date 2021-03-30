#include "Constants.h"
// #include <string.h>
#include <frc/shuffleboard/Shuffleboard.h>
#include "networktables/NetworkTable.h"
#include <wpi/StringMap.h>
#include "rev/CANSparkMax.h"
// #include "frc/WPIlib.h"
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

    if (motorType == custom2498::MotorControllerType::SparkMax)
    {
        // canControllerSpark = rev::CANSparkMax(can_id, rev::CANSparkMax::MotorType::kBrushed);
        rev::CANSparkMax canControllerSparkLocal{can_id, rev::CANSparkMax::MotorType::kBrushed};
        canControllerSpark = &canControllerSparkLocal;
    }
    else if (motorType == custom2498::MotorControllerType::TalonSRX)
    {
        ctre::phoenix::motorcontrol::can::WPI_TalonSRX canControllerTalonLocal{can_id};
        canControllerTalon = &canControllerTalonLocal;
    }
    else
    {
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

custom2498::LoadedMotors::LoadedMotors(std::vector<MotorControllerInfo> MotorControllerInfoVectorParam, bool robotDrive /*= false*/, MotorControllerType robotDriveControllerType /**/, int fr /*= 0*/, int fl /*= 0*/, int rr /*= 0*/, int rl /*= 0*/)
{
    // TODO: figure out how to use pointers instead of copying the vector like an idiot
    std::vector<MotorControllerInfo> MotorControllerInfoVector(MotorControllerInfoVectorParam);
    if (robotDrive == true)
    {
        if (robotDriveControllerType == custom2498::MotorControllerType::SparkMax)
        {
            rev::CANSparkMax frontRightMotorControllerInfo = *getMotorControllerInfoByCan_id(fr).canControllerSpark;
            rev::CANSparkMax frontLeftMotorControllerInfo = *getMotorControllerInfoByCan_id(fl).canControllerSpark;
            rev::CANSparkMax rearRightMotorControllerInfo = *getMotorControllerInfoByCan_id(rr).canControllerSpark;
            rev::CANSparkMax rearLeftMotorControllerInfo = *getMotorControllerInfoByCan_id(rl).canControllerSpark;
            frc::MecanumDrive mecanumDriveLocal{
                frontLeftMotorControllerInfo,
                rearLeftMotorControllerInfo,
                frontRightMotorControllerInfo,
                rearRightMotorControllerInfo};
            mecanumDrive = &mecanumDriveLocal;
        }
        else if (robotDriveControllerType == custom2498::MotorControllerType::TalonSRX)
        {
            ctre::phoenix::motorcontrol::can::WPI_TalonSRX frontRightMotorControllerInfo = *getMotorControllerInfoByCan_id(fr).canControllerTalon;
            ctre::phoenix::motorcontrol::can::WPI_TalonSRX frontLeftMotorControllerInfo = *getMotorControllerInfoByCan_id(fl).canControllerTalon;
            ctre::phoenix::motorcontrol::can::WPI_TalonSRX rearRightMotorControllerInfo = *getMotorControllerInfoByCan_id(rr).canControllerTalon;
            ctre::phoenix::motorcontrol::can::WPI_TalonSRX rearLeftMotorControllerInfo = *getMotorControllerInfoByCan_id(rl).canControllerTalon;
            frc::MecanumDrive mecanumDriveLocal {
                frontLeftMotorControllerInfo,
                rearLeftMotorControllerInfo,
                frontRightMotorControllerInfo,
                rearRightMotorControllerInfo
            };
            mecanumDrive = &mecanumDriveLocal;
        }
        else
        {
            throw "Invalid robotDrive MotorControllerType";
        }
    }
}

custom2498::LoadedMotors custom2498::LoadedMotors::FromJSON(std::string jsonFilename)
{
    // TODO: parse json
    // return LoadedMotors
    // placeholder for now
    return custom2498::LoadedMotors{
        std::vector<custom2498::MotorControllerInfo>{
            custom2498::MotorControllerInfo{
                "Green",
                5,
                custom2498::MotorControllerType::SparkMax},
            custom2498::MotorControllerInfo{
                "Intake Tunnel",
                6,
                custom2498::MotorControllerType::SparkMax}}};
}

std::vector<custom2498::MotorControllerInfo> custom2498::LoadedMotors::GetMotorControllerInfoVector()
{
    return MotorControllerInfoVector;
}

// void MotorControllerInfo::setMotorControlSlider(NetworkTableEntry &entry)
// {

// };

// #include <type_traits>

// #include <rev/CANSparkMax.h>
// #include <ctre/I dunno/WPI_TalonSRX.h>

// template <typename Motor>
// class Motor {
// ...
//     double Get() {
//         if constexpr (std::is_same_v<T, rev::CANSparkMax>) {
//             // Do a REV thing
//         } else (std::is_same_v<T, ctre..<i'm lazy>..WPI_TalonSRX>) {
//             // Do a CTRE thing
//         } else {
//             static_assert(false, "Invalid motor controller type given");
//         }
//     }
// };
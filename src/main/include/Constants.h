#pragma once
#include <frc/shuffleboard/Shuffleboard.h>
#include "networktables/NetworkTable.h"
#include <string.h>
#include <wpi/StringMap.h>
#include "rev/CANSparkMax.h"
#include "ctre/Phoenix.h"
#include <frc/drive/MecanumDrive.h>
#include <type_traits>

// using namespace std;
// using namespace nt;

const std::string tabName = "Motor Controller Dashboard!";

namespace custom2498
{
    // TODO: rename to something that won't be confused as brushed vs brushless
    // because MotorType really should be something along the lines of MotorControllerType
    enum MotorControllerType
    {
        SparkMax,
        TalonSRX,
        Other
    };

    // determines whether or not to use PID controls
    // or PWM controls
    enum MotorControlMode
    {
        PID,
        PWM
    };

    // custom class that contains the label/name,
    // the type of motor controller, and the type of motorControlSlider
    template <typename MotorControllerInfo>
    class MotorControllerInfo
    {
    public:
        std::string name;
        // void setMotorControlSlider(NetworkTableEntry &entry);
        double GetMotorControlSliderValue();
        void UpdateMotorController();
        const rev::CANSparkMax *canControllerSpark;
        const ctre::phoenix::motorcontrol::can::WPI_TalonSRX *canControllerTalon;
        MotorControllerInfo(std::string nameParam, int can_idParam, MotorControllerType MotorTypeParam);
    private:
        MotorControllerType motorType;
        int can_id;
        const nt::NetworkTableEntry motorControlSlider;
        // TODO: implement initializor for spark max and talons ig?
    protected:
        // nothing
    };

    class LoadedMotors
    {
    public:
        LoadedMotors FromJSON(std::string jsonFilename);
        std::vector<MotorControllerInfo> GetMotorControllerInfoVector();
        LoadedMotors(std::vector<MotorControllerInfo> motorControllerInfoVector, bool robotDrive = false, MotorControllerType robotDriveControllerType = MotorControllerType::Other, int fr = -1, int fl = -1, int rr = -1, int rl = -1);
    private:
        custom2498::MotorControllerInfo getMotorControllerInfoByCan_id(int can_id);
        std::vector<MotorControllerInfo> MotorControllerInfoVector;
        const frc::MecanumDrive *mecanumDrive;
    protected:
        // nothing
    };
} // namespace custom2498
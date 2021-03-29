#pragma once
#include <frc/shuffleboard/Shuffleboard.h>
#include "networktables/NetworkTable.h"
#include <string.h>
#include <wpi/StringMap.h>
#include "rev/CANSparkMax.h"
#include "ctre/Phoenix.h"

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
    class MotorControllerInfo
    {
    public:
        std::string name;
        // void setMotorControlSlider(NetworkTableEntry &entry);
        double GetMotorControlSliderValue();
        MotorControllerInfo(std::string nameParam, int can_idParam, MotorControllerType MotorTypeParam);

    private:
        MotorControllerType motorType;
        int can_id;
        const nt::NetworkTableEntry motorControlSlider;
        // TODO: implement initializor for spark max and talons ig?
        const rev::CANSparkMax *canControllerSpark;
        ctre::phoenix::motorcontrol::can::WPI_TalonSRX *canControllerTalon;
    protected:
        // nothing
    };

    class LoadedMotors
    {
    public:
        LoadedMotors FromJSON(std::string jsonFilename);
        std::vector<MotorControllerInfo> GetMotorControllerInfoVector();
        LoadedMotors(std::vector<MotorControllerInfo> motorControllerInfoVector);
    private:
        std::vector<MotorControllerInfo> MotorControllerInfoVector;
    protected:
        // nothing
    };
} // namespace custom
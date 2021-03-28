#pragma once
#include <string>
#include "networktables/NetworkTable.h"

using namespace std;
using namespace nt;

const string tabName = "Motor Controller Dashboard!";

namespace custom2498
{
    // TODO: rename to something that won't be confused as brushed vs brushless
    // because MotorType really should be something along the lines of MotorControllerType
    enum MotorType
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
        MotorControllerInfo(std::string nameParam, int can_idParam, MotorType MotorTypeParam);

    private:
        MotorType motorType;
        int can_id;
        const nt::NetworkTableEntry motorControlSlider;
        // TODO: implement initializor for spark max and talons ig?
        rev::CANSparkMax canControllerSpark;
        ctre::phoenix::motorcontrol::can::WPI_TalonSRX canControllerTalon;
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
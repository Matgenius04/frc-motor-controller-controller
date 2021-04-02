#pragma once
#include "MotorController.h"
#include <rev/CANSparkMax.h>
namespace custom2498
{
    class SparkMAX : public MotorController
    {
    public:
        SparkMAX(int canId, rev::CANSparkMax::MotorType MotorType);
        virtual void SetSpeed(double speed);
        // probably should be a virtual function and use type CANSparkMax
        virtual frc::SpeedController* GetSpeedController();

    private:
        rev::CANSparkMax *motorControllerPointer_;
    };
} // namespace custom2498
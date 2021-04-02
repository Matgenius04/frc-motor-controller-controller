#pragma once
#include "MotorController.h"
#include <ctre/Phoenix.h>
namespace custom2498
{
    class TalonSRX : public MotorController
    {
    public:
        TalonSRX(int canId);
        virtual void SetSpeed(double speed);
        // probably should be a virtual functions
        virtual frc::SpeedController* GetSpeedController();

    private:
        ctre::phoenix::motorcontrol::can::WPI_TalonSRX *motorControllerPointer_;
    };
};
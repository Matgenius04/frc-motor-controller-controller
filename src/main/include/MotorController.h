#pragma once
#include "frc/SpeedController.h"
#include "Updatable.h"
// parent class for SparkMax and Talon Controllers
// Use virtual methods to initalize and update speed values of each type of controller

// also for later
// enum MotorControllerType
// {
//     SparkMAX,
//     TalonSRX
// };
namespace custom2498
{
    class MotorController : public Updatable
    {
    public:
        MotorController(int canId);
        // for later.....
        // MotorController(int canId, MotorControllerType motorControllerType);
        virtual void SetSpeed(double speed) = 0;
        virtual frc::SpeedController* GetSpeedController() = 0;
        void Update(nt::Value* value);
    private:
        // speed set by operator
        int speed_;

        // unique device id / can id
        int canId_;

    protected:
        // nothing yet
    };
} // namespace custom2498

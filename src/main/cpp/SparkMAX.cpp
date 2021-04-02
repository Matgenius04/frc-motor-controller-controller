#include "SparkMAX.h"

using namespace rev;

// Constructor for SparkMax
custom2498::SparkMAX::SparkMAX(int canId, CANSparkMax::MotorType motorType)
    : MotorController(canId)
{
    motorControllerPointer_ = new CANSparkMax(canId, motorType);
}

// Define SetSpeed fucntion for SparkMAX
void custom2498::SparkMAX::SetSpeed(double speed) {
    motorControllerPointer_->Set(speed);
}

frc::SpeedController* custom2498::SparkMAX::GetSpeedController()
{
    return motorControllerPointer_;
}
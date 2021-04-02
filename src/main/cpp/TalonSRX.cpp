#include "TalonSRX.h"


custom2498::TalonSRX::TalonSRX(int canId)
    : MotorController(canId)
{
    motorControllerPointer_ = new ctre::phoenix::motorcontrol::can::WPI_TalonSRX(canId);
}

void custom2498::TalonSRX::SetSpeed(double speed) {
    motorControllerPointer_->Set(ControlMode::PercentOutput,speed);
}

frc::SpeedController* custom2498::TalonSRX::GetSpeedController()
{
    return motorControllerPointer_;
}
#include "Mecanum.h"
custom2498::MecanumDrive::MecanumDrive(
    MotorController *fr,
    MotorController *rr,
    MotorController *fl,
    MotorController *rl,
    frc::Joystick stick,
    frc::Joystick throttle)
    : mecanumDrive_(
        *fr->GetSpeedController(),
        *rr->GetSpeedController(),
        *fl->GetSpeedController(),
        *rl->GetSpeedController()
    )
    , pigeonIMUAvailable_(false)
{
    // nothing
}

custom2498::MecanumDrive::MecanumDrive(
    MotorController *fr,
    MotorController *rr,
    MotorController *fl,
    MotorController *rl,
    frc::Joystick stick,
    frc::Joystick throttle,
    ctre::phoenix::sensors::PigeonIMU pigeonIMU)
    : fr_(fr)
    , rr_(rr)
    , fl_(fl)
    , rl_(rl)
    , stick_(&stick)
    , throttle_(&throttle)
    , mecanumDrive_(
        *fr_->GetSpeedController(),
        *rr_->GetSpeedController(),
        *fl_->GetSpeedController(),
        *rl_->GetSpeedController()
    )
    , pigeonIMU_(&pigeonIMU)
    , pigeonIMUAvailable_(true)
{
    // nothing
}

void custom2498::MecanumDrive::Update()
{
    if (pigeonIMUAvailable_)
    {
        // not certain about these controls
        mecanumDrive_.DriveCartesian(stick_->GetX(),throttle_->GetY(),stick_->GetY());
    }
    else
    {
        double gyroAngle = pigeonIMU_->GetAbsoluteCompassHeading();
        // not certain about these controls
        mecanumDrive_.DriveCartesian(stick_->GetX(),throttle_->GetY(),stick_->GetY(),gyroAngle);
    }
}

#include "Mecanum.h"
custom2498::MecanumDrive::MecanumDrive(
    MotorController *fr,
    MotorController *rr,
    MotorController *fl,
    MotorController *rl,
    frc::Joystick *stick,
    frc::Joystick *throttle)
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
    frc::Joystick *stick,
    frc::Joystick *throttle,
    ctre::phoenix::sensors::PigeonIMU* pigeonIMU)
    : fr_(fr)
    , rr_(rr)
    , fl_(fl)
    , rl_(rl)
    , stick_(stick)
    , throttle_(throttle)
    , mecanumDrive_(
        *fr_->GetSpeedController(),
        *rr_->GetSpeedController(),
        *fl_->GetSpeedController(),
        *rl_->GetSpeedController()
    )
    , pigeonIMU_(pigeonIMU)
    , pigeonIMUAvailable_(true)
{
    // nothing
}

// TODO: change so that value is either used, or Mecanum isn't a
// updatable...
void custom2498::MecanumDrive::Update(nt::Value* value)
{
    /* WARNING */
    // testing elif
    // delete later
    if (value->IsBoolean())
    {
        std::cout << "Mecanum Drive is of type"<< "Boolean" << std::endl;
    } else if (value->IsBooleanArray())
    {
        std::cout << "Mecanum Drive is of type"<< "BooleanArray" << std::endl;
    } else if (value->IsDouble())
    {
        std::cout << "Mecanum Drive is of type"<< "Double" << std::endl;
    } else if (value->IsDoubleArray())
    {
        std::cout << "Mecanum Drive is of type"<< "DoubleArray" << std::endl;
    } else if (value->IsRaw())
    {
        std::cout << "Mecanum Drive is of type"<< "Raw" << std::endl;
    } else if (value->IsRpc())
    {
        std::cout << "Mecanum Drive is of type"<< "Rpc" << std::endl;
    } else if (value->IsString())
    {
        std::cout << "Mecanum Drive is of type"<< "String" << std::endl;
    } else if (value->IsStringArray())
    {
        std::cout << "Mecanum Drive is of type"<< "StringArray" << std::endl;
    } else 
    {
        std::cout << "I have no idea what type it is" << std::endl;
    }
    /* END OF TESTING */


    if (pigeonIMUAvailable_)
    {
        // not certain about these controls
        // these controls are Saji Champlin's so yeah
        mecanumDrive_.DriveCartesian(pow(stick_->GetX(),3)*-1, pow(stick_->GetY(),3),pow(throttle_->GetX(),3) * .7);
    }
    else
    {
        double gyroAngle = pigeonIMU_->GetAbsoluteCompassHeading();
        // not certain about these controls
        // and whether field-oriented drive is a good idea or not?
        mecanumDrive_.DriveCartesian(pow(stick_->GetX(),3)*-1, pow(stick_->GetY(),3),pow(throttle_->GetX(),3) * .7, gyroAngle);
    }
}

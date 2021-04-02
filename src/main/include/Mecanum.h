#include "MotorController.h"
#include <ctre/phoenix/sensors/PigeonIMU.h>
#include <frc/Joystick.h>
#include <frc/drive/MecanumDrive.h>
#pragma once
namespace custom2498
{
    class MecanumDrive
    {
    public:
        MecanumDrive(
            MotorController *fr,
            MotorController *rr,
            MotorController *fl,
            MotorController *rl,
            frc::Joystick stick,
            frc::Joystick throttle);
        MecanumDrive(
            MotorController *fr,
            MotorController *rr,
            MotorController *fl,
            MotorController *rl,
            frc::Joystick stick,
            frc::Joystick throttle,
            ctre::phoenix::sensors::PigeonIMU pigeonIMU);
        void Update();

    private:
        MotorController* fr_;
        MotorController* rr_;
        MotorController* fl_;
        MotorController* rl_;
        frc::Joystick* stick_;
        frc::Joystick* throttle_;
        ctre::phoenix::sensors::PigeonIMU* pigeonIMU_;
        frc::MecanumDrive mecanumDrive_;
        bool pigeonIMUAvailable_;
    };
} // namespace custom2498
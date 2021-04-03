#include "Widgets/MecanumDriveBase.h"

custom2498::Widgets::MecanumDriveBase::MecanumDriveBase(std::string title, std::string tab)
    : Widget(title, tab)
{
    // prolly bad practice but......
    networkTableEntry_ = InitNetworkTable();
}

nt::NetworkTableEntry custom2498::Widgets::MecanumDriveBase::InitNetworkTable()
{
    return frc::Shuffleboard::GetTab(tab_)
        .Add(title_, 0)
        .WithWidget(frc::BuiltInWidgets::kMecanumDrive)
        .GetEntry();
}
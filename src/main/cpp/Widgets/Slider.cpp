#include "Widgets/Slider.h"

custom2498::Widgets::Slider::Slider(std::string title, std::string tab)
    :   Widget(title, tab)
{
    // prolly bad practice but......
    networkTableEntry_ = InitNetworkTable();
}

nt::NetworkTableEntry custom2498::Widgets::Slider::InitNetworkTable()
{
    // hard coded min and max of one is temporary!
    wpi::StringMap<std::shared_ptr<nt::Value>> properties {
        std::make_pair("min", nt::Value::MakeDouble(-1)),
        std::make_pair("max", nt::Value::MakeDouble(1))
    };
    return frc::Shuffleboard::GetTab(tab_)
        .Add(title_, 0)
        .WithWidget(frc::BuiltInWidgets{frc::BuiltInWidgets::kNumberSlider})
        .GetEntry();
}
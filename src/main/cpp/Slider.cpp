#include "Slider.h"

custom2498::Slider::Slider(std::string title, std::string tab) 
{
    // hard coded min and max of one is temporary!
    wpi::StringMap<std::shared_ptr<nt::Value>> properties {
        std::make_pair("min", nt::Value::MakeDouble(-1)),
        std::make_pair("max", nt::Value::MakeDouble(1))
    };
    networkTable_ = frc::Shuffleboard::GetTab(tab)
        .Add(title, 0)
        .WithWidget(frc::BuiltInWidgets{frc::BuiltInWidgets::kNumberSlider})
        .WithProperties(properties)
        .GetEntry();
}

double custom2498::Slider::GetSliderData()
{
    return networkTable_.GetDouble(0.0);
}

void custom2498::Slider::SetSliderData(double number)
{
    networkTable_.SetDouble(number);
}
#pragma once
#include <wpi/StringRef.h>
#include "networktables/NetworkTable.h"
#include "frc/shuffleboard/Shuffleboard.h"
namespace custom2498
{
    class Slider
    {
    public:
        Slider(std::string title, std::string tab);
        double GetSliderData();
        void SetSliderData(double number);

    private:
        nt::NetworkTableEntry networkTable_;
        std::string title_;
    };
} // namespace custom2498
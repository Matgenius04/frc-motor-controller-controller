#pragma once
#include "Widgets/Widget.h"
#include <wpi/StringRef.h>
#include "networktables/NetworkTable.h"
#include "frc/shuffleboard/Shuffleboard.h"
namespace custom2498::Widgets
{
    class Slider : public Widget
    {
    public:
        Slider(std::string title, std::string tab);
        nt::NetworkTableEntry InitNetworkTable();

    private:
        // nothing
    };
} // namespace custom2498
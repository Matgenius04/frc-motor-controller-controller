#pragma once
#include "Slider.h"
#include "frc/shuffleboard/Shuffleboard.h"
#include "Updatable.h"
#include <utility>
#include <string>

// Shuffleboard abstraction class that for now only uses
// sliders?
namespace custom2498
{
    class GUI
    {
    public:
        GUI(std::string tabName);
        void AddSlider(std::string title, std::string tab, Updatable *updatable);
        void UpdateAll();

    private:
        std::string tabName_;

        // Create map guiMap with string as key and Slider as value
        std::vector<std::pair<Slider *, Updatable *>> guiVector_;

    protected:
        // nothing
    };
} // namespace custom2498
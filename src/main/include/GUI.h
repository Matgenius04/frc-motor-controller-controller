#pragma once
#include "Widgets/Widget.h"
#include "frc/shuffleboard/Shuffleboard.h"
#include "Widgets/Widget.h"
#include "Widgets/Slider.h"
#include "Widgets/MecanumDriveBase.h"
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
        void AddMecanum(std::string title, std::string tab, Updatable *updatable);
        void UpdateAll();

    private:
        std::string tabName_;

        // Create vector updatableVector with string as key and Slider as value
        std::vector<std::pair<Widgets::Widget *, Updatable *>> updatableVector_;

        // std::vector<std::pair<Widget *, Gettable *>> GettableVector_;

    protected:
        // nothing
    };
} // namespace custom2498
#include "GUI.h"

custom2498::GUI::GUI(std::string tabName)
   :  tabName_(tabName)
{
    frc::Shuffleboard::GetTab(tabName_);
}

void custom2498::GUI::AddSlider(std::string title, std::string tab, Updatable* updatable)
{
    guiVector_.push_back(
        std::pair<custom2498::Slider*, custom2498::Updatable *>(
            new custom2498::Slider(title, tab), updatable)
        );
}

void custom2498::GUI::UpdateAll()
{
    for (std::pair<custom2498::Slider*, custom2498::Updatable *> pair : guiVector_)
    {
        pair.second->Update(pair.first->GetSliderData());
    }
}
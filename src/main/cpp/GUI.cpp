#include "GUI.h"

custom2498::GUI::GUI(std::string tabName)
   :  tabName_(tabName)
{
    frc::Shuffleboard::GetTab(tabName_);
}

void custom2498::GUI::AddSlider(std::string title, std::string tab,Updatable* updatable)
{
        updatableVector_.push_back(
        std::pair<custom2498::Widgets::Widget *, custom2498::Updatable *>(
            new custom2498::Widgets::Slider(title, tab), 
            updatable
            )
        );
}

void custom2498::GUI::AddMecanum(std::string title, std::string tab,Updatable* updatable)
{
        updatableVector_.push_back(
        std::pair<custom2498::Widgets::Widget *, custom2498::Updatable *>(
            new custom2498::Widgets::MecanumDriveBase(title, tab), 
            updatable
            )
        );
}

void custom2498::GUI::UpdateAll()
{
    for (std::pair<custom2498::Widgets::Widget *, custom2498::Updatable *> pair : updatableVector_)
    {
        pair.second->Update(pair.first->GetValue());
    }
}
#pragma once
#include <string>
#include "networktables/NetworkTable.h"
namespace custom2498::Widgets
{
    class Widget
    {
        public:
            Widget(std::string title, std::string tab);
            virtual nt::NetworkTableEntry InitNetworkTable() = 0;
            void SetValue(nt::Value *);
            nt::Value* GetValue();
        protected:
            nt::NetworkTableEntry networkTableEntry_;
            std::string title_;
            std::string tab_;
    };
}
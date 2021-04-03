#include "Widgets/Widget.h"
custom2498::Widgets::Widget::Widget(std::string title, std::string tab)
    : title_(title)
    , tab_(tab)
{
    // nothing
}

void custom2498::Widgets::Widget::SetValue(nt::Value * value)
{
    networkTableEntry_.SetValue(std::shared_ptr<nt::Value>{value});
}

nt::Value* custom2498::Widgets::Widget::GetValue()
{
    // lmao this is sooooo wrong
    return &*networkTableEntry_.GetValue();
}
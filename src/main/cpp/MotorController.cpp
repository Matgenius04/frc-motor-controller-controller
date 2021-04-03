#include "MotorController.h"

custom2498::MotorController::MotorController(int canId)
    : canId_(canId)
{
    // nothing
}

void custom2498::MotorController::Update(nt::Value* value)
{
    SetSpeed(value->GetDouble());
}
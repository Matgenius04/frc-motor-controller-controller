#pragma once


namespace custom2498
{
    class Updatable
    {
    public:
        Updatable();
        // If other types are needed, add overload
        // functions that accept desired type.
        virtual void Update(double number) = 0; 
    };
} // namespace custom2498
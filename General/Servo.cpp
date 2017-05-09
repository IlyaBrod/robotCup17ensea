#include "Servo.h"


Servo::Servo(PinName p) : pin(p)
{
    pin.period_ms(20);
}


void Servo::setDuty(float alpha)
{
    pin.write(alpha);
}

void Servo::write(int deg)
{
    float range = max-min;
    setDuty(min+deg*range/180);
}

void Servo::stop()
{
    setDuty(0);
}

void Servo::setRange(float value1, float value2)
{
    max+=value1;
    min+=value2;
}


void Servo::resetRange()
{
    max=DEFAULT_MAX;
    min=DEFAULT_MIN;
}



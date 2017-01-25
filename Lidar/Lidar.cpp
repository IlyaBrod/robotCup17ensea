#include "Lidar.hpp"

Lidar::Lidar() : PwmStepMotor(PB_4)
{
    analyser = MapAnalyser();
    sensor = InterruptIn(PA_4);
    sensor.rise(&link);
    sensor.fall(&link);
}

Lidar::Lidar(PinName pinMotor, PinName pinSensor) : PwmStepMotor(pinMotor)
{
    analyser = MapAnalyser();
    sensor = InterruptIn(pinSensor);
    sensor.rise(&link);
    sensor.fall(&link);
}

void Lidar::link()
{
    analyser.add_Angle(readAngle());
}
#include "Lidar.hpp"

Lidar::Lidar() : PwmStepMotor(PB_4), sensor(PA_4),pc(USBTX,USBRX)
{
    analyser = MapAnalyser();
    sensor.rise(this,&Lidar::link);
    sensor.fall(this,&Lidar::link);
}

Lidar::Lidar(PinName pinMotor, PinName pinSensor) : PwmStepMotor(pinMotor), sensor(pinSensor),pc(USBTX,USBRX)
{
    analyser = MapAnalyser();
    sensor.rise(this,&Lidar::link);
    sensor.fall(this,&Lidar::link);
}

void Lidar::link()
{
    analyser.add_Angle(readAngle());
}



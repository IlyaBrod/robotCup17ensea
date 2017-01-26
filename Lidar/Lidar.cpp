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

void Lidar::print()
{
    print_Side();
    print_Orientation();
    print_Count();
    print_Beacons();
}

void Lidar::print_Side()
{
    if(analyser.get_Side()==YELLOW)
    {
        pc.printf("Team Blue\n");
    }
    else
    {
        pc.printf("Team Yellow\n");
    }
}

void Lidar::print_Orientation()
{
    float angle = analyser.get_Orientation();
    pc.printf("Orientation : %f\n",&angle);
}

void Lidar::print_Count()
{
    int number = analyser.count();
    pc.printf("Available beacons : %d\n",&number);
}

void Lidar::print_Beacons()
{
    std::vector<Balise>* balises = analyser.get_Data();
    
    for(unsigned int i=0;i<balises -> size();i++)
    {
        pc.printf("Balise %d",(*balises)[i].ID);
        if((*balises)[i].get_State())
        {
            pc.printf("ACTIVE\n");
        }
        else
        {
            pc.printf("DESACTIVE\n");
        }

        
        pc.printf("DELTA : ");
        pc.printf("%f",&(*balises)[i].DELTA);
        pc.printf(" ANGLE : ");
        pc.printf("%f",&(*balises)[i].ANGLE);
        pc.printf("\n");
    }
}
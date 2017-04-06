#include "Lidar.hpp"

#include "IncludeAll.h"


Lidar::Lidar(PinName pinMotor, PinName pinSensor) : PwmStepMotor(pinMotor), sensor(pinSensor)
{
    analyser = MapAnalyser();
    sensor.rise(callback(this,&Lidar::link));
    sensor.fall(callback(this,&Lidar::link));
    sensor.disable_irq();
}

void Lidar::link()
{

    pause();
    revAngle();
    analyser.add_Angle(getAngle());
    #ifdef DEBUG_SPY_LIDAR
    print_Angles();
    #endif //DEBUG_SPY_LIDAR
    start();

}


void Lidar::print_Angles()
{
    float angle = getAngle();
    
    GeneralItem::DEBUG_PC.printf("RAW Angle : %f\n\r", angle);
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
       GeneralItem::DEBUG_PC.printf("Team Blue\n");
    }
    else
    {
       GeneralItem::DEBUG_PC.printf("Team Yellow\n");
    }
}

void Lidar::print_Orientation()
{
    float angle = analyser.get_Orientation();
    GeneralItem::DEBUG_PC.printf("Orientation : %f\n",&angle);
}

void Lidar::print_Count()
{
    int number = analyser.count();
    GeneralItem::DEBUG_PC.printf("Available beacons : %d\n",&number);
}

void Lidar::print_Beacons()
{
    std::vector<Balise>* balises = analyser.get_Data();
    
    for(unsigned int i=0;i<balises -> size();i++)
    {
      GeneralItem::DEBUG_PC.printf("Balise %d",(*balises)[i].ID);
        if((*balises)[i].get_State())
        {
       GeneralItem::DEBUG_PC.printf("ACTIVE\n");
        }
        else
        {
         GeneralItem::DEBUG_PC.printf("DESACTIVE\n");
        }

        
        GeneralItem::DEBUG_PC.printf("DELTA : ");
        GeneralItem::DEBUG_PC.printf("%f",&(*balises)[i].DELTA);
        GeneralItem::DEBUG_PC.printf(" ANGLE : ");
        GeneralItem::DEBUG_PC.printf("%f",&(*balises)[i].ANGLE);
        GeneralItem::DEBUG_PC.printf("\n");
        
    }
}


void Lidar::start()
{
        sensor.enable_irq();
        PwmStepMotor::start();

}

void Lidar::pause()
{
    sensor.disable_irq();
    PwmStepMotor::pause();
}
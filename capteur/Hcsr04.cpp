#include "Hcsr04.hpp"

Hcsr04::Hcsr04(PinName pecho, PinName ptrig): echo(pecho), trig(ptrig)
{
    
    update.attach(callback(this,&Hcsr04::ping_1),TIME_SET/1000.0);
    
}

float Hcsr04::get_distance(void)
{
    return distance;
}



void Hcsr04::ping_1(void)
{
    activite = true;
    trig = 1;
    wait_us(10);
    trig = 0;
    echo.rise(callback(this,&Hcsr04::ping_3));
 
}
//void Hcsr04::ping_2()

void Hcsr04::ping_3()
{
    echotime = GeneralItem::sinceInitUsTimer.read_us();
    echo.fall(callback(this,&Hcsr04::ping_4));
}
void Hcsr04::ping_4()
{
    
    echotime = GeneralItem::sinceInitUsTimer.read_us() - echotime;
    distance = echotime / 58.0;
    echo.rise(NULL);
    echo.fall(NULL);
    activite = false;

}
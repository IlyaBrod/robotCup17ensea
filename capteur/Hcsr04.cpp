#include "Hcsr04.hpp"

Hcsr04::Hcsr04(PinName pecho, PinName ptrig): echo(pecho), trig(ptrig)
{
    echo.rise(callback(this,&Hcsr04::ping_3));
    echo.fall(callback(this,&Hcsr04::ping_4));
    echo.disable_irq();
}

float Hcsr04::get_distance(void)
{
    return distance;
}



void Hcsr04::ping_1()
{
    activite = true;
    trig = 1;
    wait_us(10);
    trig = 0;
    echo.enable_irq();
 
}
//void Hcsr04::ping_2()

void Hcsr04::ping_3()
{
    echotime = GeneralItem::sinceInitUsTimer.read_us();
}
void Hcsr04::ping_4()
{
    
    echotime = GeneralItem::sinceInitUsTimer.read_us() - echotime;
    distance = echotime / 58.0;
    echo.disable_irq();
    activite = false;

}
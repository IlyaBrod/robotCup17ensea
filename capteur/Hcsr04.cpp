




#include "Hcsr04.hpp"
//#define DEBUG_hcsr


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

    #ifdef DEBUG_hcsr
    //GeneralItem::DEBUG_PC.printf("ping1\n\r");
    #endif
 
}
//void Hcsr04::ping_2()

void Hcsr04::ping_3()
{
    echotime = GeneralItem::sinceInitUsTimer.read_us();
    echo.rise(NULL);
    echo.fall(callback(this,&Hcsr04::ping_4));
    #ifdef DEBUG_hcsr
    //GeneralItem::DEBUG_PC.printf("ping3\n\r");
    #endif

}
void Hcsr04::ping_4()
{
    
    echotime = GeneralItem::sinceInitUsTimer.read_us() - echotime;
    distance = echotime / 58.8;
    
    echo.fall(NULL);
    activite = false;
    #ifdef DEBUG_hcsr
    //GeneralItem::DEBUG_PC.printf("ping4\n\r");
    #endif

}
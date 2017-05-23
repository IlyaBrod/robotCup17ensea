#ifndef HCSR04
#define HCSR04
#include "IncludeAll.h"
#define TIME_SET 250

class Hcsr04
{
    protected:
        InterruptIn echo;
        DigitalOut trig;
        Ticker update;
        float distance;
        int echotime;
        


    public:
    bool activite;
        float get_distance(void);

        void ping_1 (void);
       // void ping_2 (void);
        void ping_3 (void);
        void ping_4 (void);

        Hcsr04(PinName pecho = D5, PinName ptrig = D6);




};






#endif //HCSR04
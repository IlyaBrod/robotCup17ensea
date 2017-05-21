#ifndef HCSR04
#define HCSR04
#include "IncludeAll.h"

class Hcsr04
{
    protected:
        InterruptIn echo;
        DigitalOut trig;
        
        float distance;
        int echotime;
        


    public:
    bool activite;
        float get_distance(void);

        void ping_1 (void);
       // void ping_2 (void);
        void ping_3 (void);
        void ping_4 (void);

        Hcsr04(PinName pecho, PinName ptrig);




};






#endif //HCSR04
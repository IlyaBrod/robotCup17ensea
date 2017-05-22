

#ifndef TIMERBOT1

#define TIMERBOT1
#define timerbot_PWMPRIOD 2
#define timerbot_PWMcycle 0.6
#define TIMERBOT1_TTours 5.0
#include "mbed.h"

class timerbot1
{
    public:
        static bool BLOCK_ROB1;
        bool BUSY;
        timerbot1(PinName _moteurg = D9,PinName _av_g1 =D8,PinName _av_g2 =D7,PinName _moteurd = D10, PinName _av_d1 = D12, PinName _av_d2 = D13, PinName _starter = D15);
        
        void start(void);
        void stop(void);

        void avant(float time_s = 1);
        void arriere(float time_s = 1);
        void droite(float angle_deg = 45);
        void gauche(float angle_deg = 45);



    private:

        void fin_action();
        PwmOut* moteurg;//(PinName pinout_pwm = D9);
        PwmOut* moteurd;//(PinName pinout_pwm = D10);
        DigitalOut av_g1;// = D8);
        DigitalOut av_g2;// = D7);
        DigitalOut av_d1;// = D12);
        DigitalOut av_d2;// = D13);
        DigitalIn *NC,*NC2;
        PinName mg;
        PinName md;
        InterruptIn starter; 
        Timeout stoper;
        Timeout action;

        
        
        

};




#endif
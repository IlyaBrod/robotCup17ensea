

#ifndef TIMERBOT1
#define TIMERBOT1
#include "mbed.h"
#include "../capteur/Hcsr04.hpp"


#define timerbot_PWMPRIOD 2
#define timerbot_PWMcycle 0.6
#define TIMERBOT1_TTours 5.0

class timerbot1
{
    public:
        static float dstop_cm;
        static bool BLOCK_ROB1;
        bool BUSY;
        timerbot1(PinName _moteurg = PA_8,PinName _av_g1 =PB_4,PinName _av_g2 =PB_10,PinName _moteurd = PA_15, PinName _av_d1 = PA_13, PinName _av_d2 = PA_14, PinName _starter = PA_3);
        void associate_Hcsr04 (Hcsr04 *capt_av_d,Hcsr04 *capt_av_g,Hcsr04 *capt_ar_d,Hcsr04 *capt_ar_g);
       
       
        void start(void);
        void stop(void);

        void avant(float time_s = 1);
        void arriere(float time_s = 1);
        void droite(float angle_deg = 45);
        void gauche(float angle_deg = 45);

        bool capteur();
        void pause(void);

    private:

        void fin_action();

        //moteur
        PwmOut* moteurg;
        PwmOut* moteurd;
        DigitalOut av_g1;
        DigitalOut av_g2;
        DigitalOut av_d1;
        DigitalOut av_d2;
        DigitalIn *NC,*NC2;
        //memoir des position des pin pour les timmers
        PinName mg;
        PinName md;



        //permet le deparage par pin a d'asactiver'
        InterruptIn starter; 


        //permet d'arretter tout au bout de 90s'
        Timeout stoper;
        //permet de stopé le robot apres une action et de lancé l'action suivante'
        Timeout action;
        
        //block interuption du fonctionnement
        //echotime permet de réarmé les interuptions en cours
        
        // last act permet de retrouvé quelle action etait en cours
        //last act : 1==avant,2==arrière,3==droite,4==gauche
        int last_act;
        //
        int echotime;
        int echoend;
        Hcsr04* capt_av_d;
        Hcsr04* capt_av_g;
        Hcsr04* capt_ar_d;
        Hcsr04* capt_ar_g;
        
        
        
        

};




#endif
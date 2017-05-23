#include "timerbot1.hpp"


bool timerbot1::BLOCK_ROB1 = true;


timerbot1::timerbot1(PinName _moteurg,PinName _av_g1,PinName _av_g2 ,PinName _moteurd, PinName _av_d1,PinName _av_d2, PinName _starter) :av_g1(_av_g1),av_g2(_av_g2),av_d1(_av_d1),av_d2(_av_d2),starter(_starter)
{
 starter.fall(callback(this,&timerbot1::start));   
 BUSY = false;
 mg = _moteurg;
 md = _moteurd;
 NC = new DigitalIn(mg);
 NC2 = new DigitalIn(md);
}

void timerbot1::start()
{
    stoper.attach(callback(this,&timerbot1::stop),89.0);
    timerbot1::BLOCK_ROB1 = false;
}


void timerbot1::associate_Hcsr04(Hcsr04 *capt_av_d,Hcsr04 *capt_av_g,Hcsr04 *capt_ar_d,Hcsr04 *capt_ar_g)
{
    this->capt_av_d = capt_av_d;
    this->capt_av_g = capt_av_g;
    this->capt_ar_d = capt_ar_d;
    this->capt_ar_g = capt_av_g;

}
void timerbot1::stop()
{
    //desactivé les autre interuptions
    action.detach();
    //quiter tt les pwm
    if (moteurd != NULL)
        {
            delete moteurd;
            moteurd = NULL;
            NC = new DigitalIn(md);
        }
    if (moteurg != NULL)
        {
            delete moteurg;
            moteurg = NULL;
            NC2 = new DigitalIn(md);
        }

    
    //ouvrir parasol
    //ne rien faire
    while (true)
    {

    }
}

void timerbot1::avant(float time_s)
{
    while (BUSY == true)
    {
         wait_ms(100);
         if (capteur(7))
            pause();
    }

        BUSY = true;
        action.attach(callback(this,&timerbot1::fin_action),time_s);

        delete NC;
        delete NC2;
        NC = NULL;
        NC2 = NULL;
        moteurg = new PwmOut(mg);
        moteurd = new PwmOut(md);
        av_g1 = 1;
        av_d1 = 1;
        av_g2 = 0;
        av_d2 = 0;

        last_act = 1;
        echotime = GeneralItem::sinceInitUsTimer.read_ms();
        echoend = echotime + (int)(time_s*1000);
        moteurg->period_ms(timerbot_PWMPRIOD);
        moteurd->period_ms(timerbot_PWMPRIOD);

        moteurg->write(timerbot_PWMcycle);
        moteurd->write(timerbot_PWMcycle);

}

void timerbot1::arriere(float time_s)
{
    while (BUSY == true)
    {
    
     wait_ms(100);
     if (capteur(7))
            pause();

    }

        BUSY = true;
        action.attach(callback(this,&timerbot1::fin_action),time_s);



        delete NC;
        delete NC2;
        NC = NULL;
        NC2 = NULL;
        moteurg = new PwmOut(mg);
        moteurd = new PwmOut(md);
        av_g1 = 0;
        av_d1 = 0;
        av_g2 = 1;
        av_d2 = 1;
        
        last_act = 2;
        echotime = GeneralItem::sinceInitUsTimer.read_ms();
        echoend = echotime + (int)(time_s*1000);
        moteurg->period_ms(timerbot_PWMPRIOD);
        moteurd->period_ms(timerbot_PWMPRIOD);

        moteurg->write(timerbot_PWMcycle);
        moteurd->write(timerbot_PWMcycle);

}

void timerbot1::droite(float angle_deg)
{
        float time_s = TIMERBOT1_TTours*angle_deg/360.0;
    while (BUSY == true)
    {
         wait_ms(100);
         if (capteur(7))
            pause();
    }

        BUSY = true;
        action.attach(callback(this,&timerbot1::fin_action),time_s);



        delete NC;
        delete NC2;
        NC = NULL;
        NC2 = NULL;
        moteurg = new PwmOut(mg);
        moteurd = new PwmOut(md);
        av_g1 = 1;
        av_d1 = 0;
        av_g2 = 0;
        av_d2 = 1;
        

        last_act = 3;
        echotime = GeneralItem::sinceInitUsTimer.read_ms();
        echoend = echotime + (int)(time_s*1000);
        moteurg->period_ms(timerbot_PWMPRIOD);
        moteurd->period_ms(timerbot_PWMPRIOD);

        moteurg->write(timerbot_PWMcycle-0.2);
        moteurd->write(timerbot_PWMcycle-0.2);

}

void timerbot1::gauche(float angle_deg)
{
        float time_s = TIMERBOT1_TTours*angle_deg/360.0;
    while (BUSY == true)
    {

         wait_ms(100);
         if (capteur(7))
            pause();
    }

        BUSY = true;
        action.attach(callback(this,&timerbot1::fin_action),time_s);


       delete NC;
        delete NC2;
        
        moteurg = new PwmOut(mg);
        moteurd = new PwmOut(md);
        av_g1 = 0;
        av_d1 = 1;
        av_g2 = 1;
        av_d2 = 0;
        
        last_act = 4;
        echotime = GeneralItem::sinceInitUsTimer.read_ms();
        moteurg->period_ms(timerbot_PWMPRIOD);
        moteurd->period_ms(timerbot_PWMPRIOD);

        moteurg->write(timerbot_PWMcycle-0.2);
        moteurd->write(timerbot_PWMcycle-0.2);

}

void timerbot1::fin_action()
{
   
    BUSY = false;
    delete moteurg;
    delete moteurd;
    #ifdef DEBUG
    wait_ms(300);
    GeneralItem::DEBUG_PC.printf("\ndebug teste %b",BUSY);
    wait_ms(300);
    #endif
    
    
    NC = new DigitalIn(mg);
    NC2 = new DigitalIn(md);
   
    wait_ms(500);

    #ifdef DEBUG
    GeneralItem::DEBUG_PC.printf("debug teste %b",BUSY);
    wait_ms(300);
    #endif

}

bool timerbot1::capteur(float dstop_cm)
{
    if (last_act == 2)
        {
            if (capt_ar_d->get_distance() < dstop_cm)
                return true;
            else if (capt_ar_d->get_distance() < dstop_cm)
                return true;
            else 
                return false;
        }
    else if (last_act == 1)
        {
            if (capt_av_d->get_distance() < dstop_cm)
                return true;
            else if (capt_av_d->get_distance() < dstop_cm)
                return true;
            else 
                return false;
        }
    else
        return false;
}


void timerbot1::pause()
{
    //tout bloquer
    //recuperer le temps manquant
    //attendre d'avoir la place'
    //redémarer
    //1
    delete moteurg;
    delete moteurd;
    NC = new DigitalIn(mg);
    NC2 = new DigitalIn(md);
    action.detach();
    BUSY = false;
    //2
    echotime = GeneralItem::sinceInitUsTimer.read_ms();
    int manque = echotime-echoend;

    //3
    while (capteur(7))
    {
        wait_ms(100);
        
            
    }

    //4
    if (last_act == 1)
        avant(manque/1000.0);
    else if (last_act == 2)
        arriere(manque/1000.0);
    else if (last_act == 3)
        droite(manque/1000.0);
    else if (last_act == 4)
        gauche(manque/1000.0);


}









#include "timerbot1.hpp"
//#define DEBUG


bool timerbot1::BLOCK_ROB1 = true;
float timerbot1::dstop_cm = 20;

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
         wait_ms(200);
         if (capteur())
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
        echoend = GeneralItem::sinceInitUsTimer.read_ms()+(int)(time_s*1000);
        moteurg->period_ms(timerbot_PWMPRIOD);
        moteurd->period_ms(timerbot_PWMPRIOD);

        moteurg->write(timerbot_PWMcycle);
        moteurd->write(timerbot_PWMcycle);

}

void timerbot1::arriere(float time_s)
{
    while (BUSY == true)
    {
    #ifdef DEBUG
    GeneralItem::DEBUG_PC.printf("bloquer dans arriere\n\r");
    
    #endif
     wait_ms(200);
     if (capteur())
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
        echoend = GeneralItem::sinceInitUsTimer.read_ms()+(int)(time_s*1000);
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
         wait_ms(200);
         if (capteur())
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
        echoend = GeneralItem::sinceInitUsTimer.read_ms()+(int)(time_s*1000);
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

         wait_ms(200);
         if (capteur())
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
        echoend = GeneralItem::sinceInitUsTimer.read_ms()+(int)(time_s*1000);
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
    GeneralItem::DEBUG_PC.printf("\n\rfin act %b",BUSY);
    wait_ms(300);
    #endif
    
    
    NC = new DigitalIn(mg);
    NC2 = new DigitalIn(md);
   
    wait_ms(500);

    #ifdef DEBUG
    GeneralItem::DEBUG_PC.printf("\n\rfin action 2 %b",BUSY);
    wait_ms(300);
    #endif

}

bool timerbot1::capteur()
{
    //vers l'arrière' ==1
    if (last_act == 2)
        {
            if (capt_ar_d->get_distance() < timerbot1::dstop_cm)
                return true;
            else if (capt_ar_d->get_distance() < timerbot1::dstop_cm)
                return true;
            else 
                return false;
        }
    //vers l'avant' ==1
    else if (last_act == 1)
        {
            if (capt_av_d->get_distance() < timerbot1::dstop_cm)
                return true;
            else if (capt_av_d->get_distance() < timerbot1::dstop_cm)
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
    echotime = GeneralItem::sinceInitUsTimer.read_ms();
    BUSY = false;
    //2
    echotime = GeneralItem::sinceInitUsTimer.read_ms();
    float manque = (float)(echoend-echotime)/1000.0;

    //3
    #ifdef DEBUG
        GeneralItem::DEBUG_PC.printf("manque : %d\n\r",manque);
    #endif

    wait_ms(200);

    //on attend qu'il y ai de la place'
    while (capteur())
    {
        wait_ms(200);
        #ifdef DEBUG
        GeneralItem::DEBUG_PC.printf("manque : %f  :::  dist = %f,%f,%f,%f\n\r",manque,capt_av_d->get_distance(),capt_av_g->get_distance(),capt_ar_d->get_distance(),capt_ar_d->get_distance());
        GeneralItem::DEBUG_PC.printf("capteur_busy : %d,%d;%d,%dn\r",capt_av_d->activite,capt_av_g->activite,capt_ar_d->activite,capt_ar_d->activite);
        #endif
            
    }

    //4
    // si manque est inf a 0 alors l'action etait terminé et on continue le programe normalment'
    if (manque > 0)
    {
    if (last_act == 1)
        avant(manque);
    else if (last_act == 2)
        arriere(manque);
    else if (last_act == 3)
        droite(manque);
    else if (last_act == 4)
        gauche(manque);
    }

}





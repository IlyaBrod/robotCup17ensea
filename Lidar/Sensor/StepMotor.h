/*
 * StepMotor.h
 *
 *  Created on: 31 oct. 2016
 *      Author: hugot
 */

#ifndef STEPMOTOR_H_
#define STEPMOTOR_H_


class StepMotor
{
    private :
        int numberOfStep;
        int stepTimerMs;
        DigitalOut stepPin;
        DigitalOut directionPin;
        int positionAngle;
        bool interuptionStepEnable;
        Ticker InteruptSteping;
    public :
        //2ms
        void one_Step (void);
        //0ms
        void direction_Toogle (void);
        //0ms
        void angle_Update(void);
        //
        int init_Interuption_Step_Timer (int ms);
        //
        int stop_Interution_Step_Timer (int ms);

        StepMotor(int numberOfStep, PinName stepPin, PinName directionPin);
        ~StepMotor();

};//end class


#endif /* STEPMOTOR_H_ */

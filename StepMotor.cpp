/*
 * StepMotor.cpp
 *
 *  Created on: 31 oct. 2016
 *      Author: hugot
 */
#include "mbed.h"
#include "StepMotor.h"
/*
*number of step : nombre de pas d'un tour du moteur
*steppin et direction_pin : control du moteur via carte
*h
*
*/
StepMotor::StepMotor(int numberOfStep, PinName stepPin, PinName directionPin) : numberOfStep(numberOfStep),stepPin(stepPin), directionPin(directionPin)
{
    interuptionStepEnable = false;
    positionAngle = 0;
    (this->stepPin) = 0;
    (this->directionPin) = 0;
}

StepMotor::~StepMotor()
{

}

void StepMotor::one_Step()
{
    wait_ms(1);
    (this->stepPin) = 1;
    wait_ms(1);
    (this->stepPin) = 0;
    this->angle_Update();
}

void StepMotor::direction_Toogle (void)
{
    if (this->directionPin == 0)
        this->directionPin = 1;
    else
        this->directionPin = 0;
}

void StepMotor::angle_Update(void)
{
    if (this->directionPin == 0)
    {
        this->positionAngle = this->positionAngle + (360.0/numberOfStep);
        if (this->positionAngle >= 360)
            this->positionAngle -= 360;
    }
    else
    {
        this->positionAngle -= (360.0/numberOfStep);
        if ( this->positionAngle < 0 )
        this->positionAngle =+ 360;
    }
}

int StepMotor::init_Interuption_Step_Timer (int ms)
{
    (this->InteruptSteping).attach_us(this,&StepMotor::one_Step,ms);
    return 0;
}

int StepMotor::stop_Interution_Step_Timer (int ms)
{
    (this->InteruptSteping).detach();
    return 0;
}




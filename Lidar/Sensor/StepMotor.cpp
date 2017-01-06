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
    this->angleUpdate();
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
    if (this->direction_pin == 0)
    {
        this->position_angle = this->position_angle + (360.0/number_of_step);
        if (this->position_angle >= 360)
            this->position_angle -= 360;
    }
    else
    {
        this->position_angle -= (360.0/number_of_step);
        if ( this->position_angle < 0 )
        this->position_angle =+ 360;
    }
}

int StepMotor::init_Interuption_Step_Timer (int ms)
{
    (this->Interupt_steping).attach_us(this,&StepMotor::One_step,ms);
    return 0;
}

int StepMotor::stop_Interution_Step_Timer (int ms)
{
    (this->Interupt_steping).detach();
    return 0;
}




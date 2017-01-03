
#include "IncludeAll.h"


using namespace std;
PwmStepMotor::PwmStepMotor(PinName pwmOut,int pwmPeriode_us,float pwmCycle, int nombreDeStepParTour, int pwmDir):pwmMoteur(pwmOut)
{
	pwmMoteur.period_us(pwmPeriode_us);
	this->pwmPeriode_us = pwmPeriode_us;
	this->pwmCycle=pwmCycle;
	this->nombreDeStepParTour=nombreDeStepParTour;
	this->pwmDir=pwmDir;
	pwmMoteur.write(0);
	angle = 0;
}


void PwmStepMotor::set(int pwmPeriode_us,float pwmCycle)
{
	this->stop();
	this->pwmPeriode_us = pwmPeriode_us;
	this->pwmCycle = pwmCycle;
}

float PwmStepMotor::readAngle()
{
	int time = GeneralItem::sinceInitUsTimer.read();
	int intertime = time - lastTime;
	lastTime = time;

	if (pwmDir == 0)
		angle += (360*intertime/((float)pwmPeriode_us*0.000001*nombreDeStepParTour));
	else if (pwmDir == 1)
		angle -= (360*intertime/((float)pwmPeriode_us*0.000001*nombreDeStepParTour));

	if (angle >= 360)
		angle -= 360;
	else if (angle < 0)
		angle += 360;

	return angle;
}

void PwmStepMotor::start()
{
	lastTime = GeneralItem::sinceInitUsTimer.read();
	pwmMoteur.period_us(pwmPeriode_us);
	pwmMoteur.write(pwmCycle);
	
}

void PwmStepMotor::stop()
{
	float useless;
	useless = readAngle();
	pwmMoteur.period_us(0);
	pwmMoteur.write(0);
}




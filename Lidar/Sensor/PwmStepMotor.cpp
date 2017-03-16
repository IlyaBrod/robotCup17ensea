
#include "IncludeAll.h"


using namespace std;
PwmStepMotor::PwmStepMotor(PinName pwmOut,int pwmPeriode_us,float pwmCycle, int nombreDeStepParTour, int pwmDir):pinOut(pwmOut)
{
	this->pwmPeriode_us = pwmPeriode_us;
	this->pwmCycle=pwmCycle;
	this->nombreDeStepParTour=nombreDeStepParTour;
	this->pwmDir=pwmDir;
	angle = 0;

}

PwmStepMotor::~PwmStepMotor()
{
	delete pwmMoteur;
}


void PwmStepMotor::set(int pwmPeriode_us,float pwmCycle,int nbStep)
{
	this->stop();
	this->pwmPeriode_us = pwmPeriode_us;
	this->pwmCycle = pwmCycle;
	this->nombreDeStepParTour = nbStep;
}


void PwmStepMotor::start()
{
	delete NC;
	pwmMoteur = new PwmOut(pinOut);
	lastTime = GeneralItem::sinceInitUsTimer.read_us();
	pwmMoteur->period_us(pwmPeriode_us);
	pwmMoteur->write(pwmCycle);
	
}

void PwmStepMotor::stop()
{
	delete pwmMoteur;
	NC = new DigitalIn(pinOut);
}

float PwmStepMotor::getAngle()
{
	return angle;
}
void PwmStepMotor::revAngle()
{
	
	float delta;
	delta = (timeDelta()*360.0) / (nombreDeStepParTour*pwmPeriode_us);
	timeSave();
	angle = angle+delta;
	while (angle > 360)
	{
		angle -= 360;
	}
	
}

void PwmStepMotor::pause()
{
	revAngle();
	delete pwmMoteur;
	NC = new DigitalIn(pinOut);
}
void PwmStepMotor::timeSave()
{
	lastTime = GeneralItem::sinceInitUsTimer.read_us();
	GeneralItem::DEBUG_PC.printf("time : %d\n\r", lastTime);
}


int PwmStepMotor::timeDelta()
{
	int delta = 0;
	delta = GeneralItem::sinceInitUsTimer.read_us() - lastTime;
	GeneralItem::DEBUG_PC.printf("delta : %d\n\r", lastTime);
	return delta;
	
}


void PwmStepMotor::printAngle()
{
	GeneralItem::DEBUG_PC.printf("angle : %f\n\r", angle);
}

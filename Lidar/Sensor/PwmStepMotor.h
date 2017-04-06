/**
 * PwmStepMotor
 *
 * fonctinement d'un moteur pas à pas via une pwm
 *
 * contien le genrateur de pwm ::
 * 		pwmm freq
 * contien le changement de direction du moteur
 * 		pwmm dir
 * contien la position angulaire du moteur
 * 		pwmm nbStep
 * 		pwmm angle
 */

#ifndef PWMSTEPMOTOR_H
#define PWMSTEPMOTOR_H

#include "mbed.h"


class PwmStepMotor
{
private:
	int pwmPeriode_us;
	int pwmDir;
	int nombreDeStepParTour;
	float pwmCycle;
	int lastTime;
	float angle;
	PinName pinOut;
	PwmOut* pwmMoteur;
	DigitalIn* NC;

public: 
	/**
	 * @param pinName				: nom de la pin utilisé
	 * @param pwmPeriode_us			: [1 micro seconde]
	 * @param cycle					: [0.5]
	 * @param nombreDeStepParTour	: [200]
	 * @param pwmDir				: [0]
	 */
	PwmStepMotor(PinName pwmOut = D13,int pwmPeriode_us = 100,float pwmCycle = 0.5, int nombreDeStepParTour = 4096, int pwmDir = 0);
	~PwmStepMotor();

	/**
	 *
	 * @param pwmPeriode_us : edit
	 * @param pwmCycle		: edit
	 */
	 public:
	void set(int pwmPeriode_us,float pwmCycle,int nbStep = 4048);

	/**
	 *
	 * @return renvoi l'angle par raport au depart du moteur
	 */
	 public:
	float getAngle();
	void revAngle();

	/**
	 *
	 * @return timer start value
	 */
	 public:

	 
	void start();
	void stop();
	void pause();

	/**
	 *
	 * @return timer stop value
	 */

	/**
	*
	*
	*/
	void print_Angle();
	void timeSave();
	int timeDelta();


};

#endif

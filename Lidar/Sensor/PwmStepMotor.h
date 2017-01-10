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



class PwmStepMotor
{
private:
	int pwmPeriode_us;
	int pwmDir;
	int nombreDeStepParTour;
	float pwmCycle;
	int lastTime;
	float angle;
	PwmOut pwmMoteur;


public :
	/**
	 * @param pinName				: nom de la pin utilisé
	 * @param pwmPeriode_us			: [1 micro seconde]
	 * @param cycle					: [0.5]
	 * @param nombreDeStepParTour	: [200]
	 * @param pwmDir				: [0]
	 */
	PwmStepMotor(PinName pwmOut,int pwmPeriode_us = 20,float pwmCycle = 0.5, int nombreDeStepParTour = 200, int pwmDir = 0);


	/**
	 *
	 * @param pwmPeriode_us : edit
	 * @param pwmCycle		: edit
	 */
	void set(int pwmPeriode_us,float pwmCycle);

	/**
	 *
	 * @return renvoi l'angle par raport au depart du moteur
	 */
	float readAngle();

	/**
	 *
	 * @return timer start value
	 */
	void start();

	/**
	 *
	 * @return timer stop value
	 */
	void stop();


};

#endif
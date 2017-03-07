#ifndef ROBOT_CLASS
#define ROBOT_CLASS

#include "../IncludeAll.h"

/* Objet Robot 
 * Contient toutes les composantes générales d'un robot
 * Ne pas spécifier les fonctions caractéristiques des robots principal et secondaire.
 */ 
 class Robot 
 {
	 private:
		Lidar lidar;
	 
	 public:
		Robot(PinName lidarpinMotor = PB_4, PinName lidarpinSensor = PA_4);

		/**
		 * Fonction où le code du robot général est placé.
		 */
		void run();

		/**
		 * Fonction qui permet de déplacer le robot
		 * @param x
		 * @param y
		 */
		void move(float x,float y);

 };

 #endif
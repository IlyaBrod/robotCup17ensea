#include "Balise.hpp"


/**
 * Initialisation de l'objet BALISE
 * @param baliseRadius
 */
Balise::Balise(float baliseRadius)
{
	this.baliseRadius = baliseRadius;
}


/**
 * Calcule la position du robot
 * à partir de la connaissance de 3 balises.
 * @param angle d'observation de la balise
 * @return objet POINT, position du robot
 */
float Balise::triangulate(float angle1, float angle2, float angle3)
{



	return 0.0;
}

/**
 * Calcule la position du robot à partir de 2
 * balises.
 * ATTENTION : cette fonction n'est pas toujours
 * valide.
 * @param angle
 * @return objet POINT, position du robot
 */
float Balise::duoangulate(float angle)
{



	return 0.0;
}


	/**
	 * Fonction qui calcule la distance robot<->balise
	 * @param angle d'observation de la balise
	 * @return distance [unité du rayon]
	 */
float calc_Dist_From_Balise(float angle)
{
	float teta = 180-angle;
	float dist = baliseRadius*sin(teta/2)/tan(angle/2)+baliseRadius*cos(teta/2) ;
	return dist;
}

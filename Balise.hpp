#include <math.h>
#include "Point.hpp"

#define ANGLE_B2 135
#define CORNER_B2 90
#define B2B1 100

/**
 * Représente le système de balise.\n
 * Permet le calcul de la position du robot par différntes méthodes.
 */
class Balise
{

private:

	float baliseRadius;
	
	/**
	 * Fonction qui calcule la distance robot<->balise
	 * @param angle Angle d'observation de la balise
	 * @return distance
	 */
	float calc_Dist_From_Balise(float angle);



public:
	/**
	 * Initialisaiton de la balise
	 * @param baliseRadius Rayon de la balise. L'unité de cette valeur détermine l'unité de tous les calculs
	 */
	Balise(float baliseRadius);

	/**
	 * Calcule la position du robot
	 * à partir de la connaissance de 3 balises.
	 * @param angle Angles d'observation des balises
	 * @return Objet Point, position du robot
	 */
	Point triangulate(float angle1, float angle2, float angle3);

	/**
	 * Calcule la position du robot à partir de 2
	 * balises.
	 * ATTENTION : cette fonction n'est pas toujours
	 * valide.
	 * @param angle Angles d'observations des balises
	 * @return objet POINT, position du robot
	 */
	Point duoangulate(float angle1,float angle2);
		
		
	float get_Orientation(float db2,float db1,float angle);
		
		
		
		
		
};

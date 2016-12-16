#include <math.h>
#include "Point.hpp"
#include "BALISE_CONFIG.hpp"


/**
 * Représente le système de balise.\n
 * Permet le calcul de la position du robot par différntes méthodes.
 */
class Balise
{

private:

	int mode;
	
	double baliseRadius;
	
	/**
	 * Fonction qui calcule la distance robot<->balise
	 * @param angle Angle d'observation de la balise
	 * @return distance
	 */
	double calc_Dist_From_Balise(float angle);

	/**
	 * Calcule le coefficient A pour la triangulation.
	 * @param r1 Distance balise 1
	 * @param r2 Distance balise 2
	 * @param n1 Norme du vecteur 1
	 * @param n2 Norme du vecteur 2 
	 */
	double tri_A_Calc(double r1,double r2,double n1, double n2);


	/**
	 * Calcule la position du robot
	 * à partir de la connaissance de 3 balises.
	 * @param angle Angles d'observation des balises
	 * @return Objet Point, position du robot
	 */
	Point triangulate(float angle1, float angle2, float angle3);


	/**
	 * Calcule la position du robot à partir de 2
	 * balises. Avec vérification du point sur le terrain
	 * ATTENTION : cette fonction n'est pas toujours
	 * valide.
	 * @param angle Angles d'observations des balises
	 * @return objet POINT, position du robot
	 */
	Point duoangulate_1(float angle1,float angle2);

	/**
	 * Calcule l'angle d'orientation du robot à partir
	 * de la balise 2 et 1.
	 * @param db2 Distance de la balise 2
	 * @param db1 Distance de la balise 1
	 * @param angle Angle d'observation de la balise 2
	 * @return Angle en degré
	 */
	float get_Orientation(float db2,float db1,float angle);


public:

	/**
	 * Change le mode de calcul de la position du robot.
	 * 0 : triangulation par distances \n
	 * 1 : triangulation par angles \n
	 * 2 : triangulation par 2 orientation \n
	 */
	void set_Mode(int newMode);
	
	
	/**
	 * Initialisaiton de la balise
	 */
	Balise();
		
	
	/**
	 * Donne la position et l'orientation du robot sur le terrain.
	 * Le calcul est fait suivant le mode choisis.
	 * @return Point
	 */
	Point get_Point();
		
};

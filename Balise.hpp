#include <math.h>
#include "Point.hpp"
#include "BALISE_CONFIG.hpp"


/**
 * Represents a beacon
 */
class Balise
{
	private:
		int ID;
		Point origine;
	public:
		
		Balise(int x,int y,int id);
		
		/**
		 * Get beacon data
		 */
		int get_ID();
		int get_X();
		int get_Y();
		
		/**
		 * Set beacon location
		 */
		void setX(int x);
		void setY(int y);
		
		
		


};

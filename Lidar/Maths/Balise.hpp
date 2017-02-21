#ifndef CLASS_BALISE_HPP
#define CLASS_BALISE_HPP

#include <vector>
#include "../../General/Point.hpp"
#include "BALISE_CONFIG.hpp"


/**
 * Represents a beacon
 * ANGLE = angle of localisation
 * DELTA = angle of observation
 */
class Balise : public Point
{
	private:
		bool active;
		
	public:
		int ID;
		float DELTA;
		float DIST;
		Balise();
		Balise(int ID);
		Balise(int x,int y,int id);
		
		/**
		 * Change the state of the beacon
		 */
		void activate();
		void desactivate();
		
		/**
		 * Return the state of the beacon
		 * @return true if active, false if desactive
		 */
		bool get_State();
	
};

/**
 * Function which search indexes of an array corresponding to a given IDs
 * @param data List of beacons
 * @param IDs list of indexes to search
 * @return List of indexes (int)
 */
int* find_Index_ID(std::vector<Balise>* data,std::vector<int>* IDs);

#endif

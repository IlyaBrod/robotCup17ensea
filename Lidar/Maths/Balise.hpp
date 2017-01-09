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
		float delta;
	public:
		int ID;
		Balise();
		Balise(int x,int y,int id);
		
		/**
		 * Change the state of the beacon
		 */
		void activate();
		void desactivate();
		bool get_State();
	
		/**
		 * Affect delta value
		 */
		float get_Delta();
		void set_Delta(float d);
};

#endif

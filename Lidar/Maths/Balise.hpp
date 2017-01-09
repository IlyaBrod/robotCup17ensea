#ifndef CLASS_BALISE_HPP
#define CLASS_BALISE_HPP

#include <vector>
#include "../../General/Point.hpp"
#include "BALISE_CONFIG.hpp"


/**
 * Represents a beacon
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
		bool getState();
};

#endif

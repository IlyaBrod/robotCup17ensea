#ifndef CLASS_BALISE_HPP
#define CLASS_BALISE_HPP

#include <vector>
#include "Point.hpp"
#include "BALISE_CONFIG.hpp"


/**
 * Represents a beacon
 */
class Balise : public Point
{

	public:
		int ID;
		Balise(int x,int y,int id);
		


};

#endif

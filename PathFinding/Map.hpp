#ifndef CLASS_MAP_DEFINED
#define CLASS_MAP_DEFINED

#include "Rectangle.hpp"

#define NBRECTS 16

class Map{
	protected :
		Rectangle obstacles[NBRECTS];
		int nbRect ;
	public :
		Map();
		~Map();
		void init();
};

#endif

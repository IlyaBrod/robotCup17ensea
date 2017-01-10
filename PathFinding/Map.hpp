#ifndef CLASS_MAP_DEFINED
#define CLASS_MAP_DEFINED

#include "../General/Rectangle.hpp"

class Map{
	protected :
		Rectangle* obstacles;
		int nbRect ;
	public :
		Map();
		~Map();
		void init();
};

#endif

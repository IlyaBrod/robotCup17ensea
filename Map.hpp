#ifndef CLASS_MAP_DEFINED
#define CLASS_MAP_DEFINED

#include "Rectangle.hpp"

class Map{
	private :
		static Rectangle* obstacles;
		static int nbRect ;
	public :
		Map();
		~Map();
		void init();
};

#endif
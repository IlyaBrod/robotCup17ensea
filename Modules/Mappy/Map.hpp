#pragma once
#ifndef CLASS_MAP
#define CLASS_MAP

#include <vector>
#include "Figure.hpp"

/**
 * Configure the terrain map.
 * Units [milimeters]
 */
class Map
{
protected:
	std::vector<Figure> map;
	double sizeX, sizeY; //map borders
public:
	/**
	* Initialise the map here
	*/
	Map();
};

#endif // !CLASS_MAP

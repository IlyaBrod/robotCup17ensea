#include "Map.hpp"

Map::Map() : sizeX(2000),sizeY(3000)
{
	Figure rect1;
	rect1.addPoint(Point(50, 50));
	rect1.addPoint(Point(50, 100));
	rect1.addPoint(Point(100, 100));
	rect1.addPoint(Point(100, 50));
	map.push_back(rect1);
}





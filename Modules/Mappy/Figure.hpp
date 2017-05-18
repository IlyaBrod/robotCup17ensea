#pragma once
#ifndef CLASS_FIGURE
#define CLASS_FIGURE

#include <vector>
#include "Point.hpp"

class Figure
{
protected:
	std::vector<Point> points;
public:

	/**
	 * Add point to the figure.
	 * Warning : Add in linking order (fellow lines)
	 * @param p Point to add
	 */
	void addPoint(Point p);

	double getX(int i);
	double getY(int i);
	unsigned int getSize();
};


#endif

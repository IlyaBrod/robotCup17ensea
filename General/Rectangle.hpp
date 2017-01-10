#ifndef CLASS_RECTANGLE_DEFINED
#define CLASS_RECTANGLE_DEFINED

#include "Point.hpp"

/**
 *	A------B
 *  |      |
 *	D------C
**/

struct Rectangle : public Point{
	public :
		double w ; //width
		double h ; //height

		Rectangle();
		Rectangle(const Point &P, const Point &Q);
		Rectangle(const double &x, const double &y, const double &w, const double &h);

		bool intersect(const Rectangle &rect);
};

#endif

#ifndef CLASS_RECTANGLE_DEFINED
#define CLASS_RECTANGLE_DEFINED

#include "GeneralFunctions.hpp"
#include "Point.hpp"

/**
 *	A------B
 *  |      |
 *	D------C
**/

class Rectangle{
	private :
		Point A,B,C,D ;

	public :
		Rectangle(): A(), B(), C(), D(){}
		Rectangle(const Point &P, const Point &Q);
		Rectangle(const Point &A, const Point &B, const Point &C, const Point&D);
		bool intersect(const Rectangle &rect);
};

#endif

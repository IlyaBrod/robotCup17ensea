#ifndef CLASS_RECTANGLE_DEFINED
#define CLASS_RECTANGLE_DEFINED

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
		Rectangle(const Point &A, const Point &B, const Point &C, const Point&D);
};

#endif
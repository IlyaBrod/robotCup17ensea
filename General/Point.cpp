#include "Point.hpp"


Point::Point()
{
	X=0.0;
	Y=0.0;
	ANGLE = 0.0 ;
}

Point::Point(const float &x, const float &y)
{
	X = x;
	Y = y;
	ANGLE = 0.0;
	
}
Point::Point(const float &x, const float &y, const float &angle)
{
	X = x;
	Y = y;
	ANGLE = angle;
	
}

Point::Point(const Point &p): X(p.X), Y(p.Y), ANGLE(p.ANGLE){}

Point& Point::operator=(const Point& p){
	X = p.X ;
	Y = p.Y ;
	ANGLE = p.ANGLE ;
	
	return *this;
}

float Point::get_Norm()
{
	return sqrt(X*X+Y*Y);
}

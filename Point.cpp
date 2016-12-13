#include "Point.hpp"


Point::Point()
{
	X=0.0;
	Y=0.0;
	ANGLE = 0.0 ;
}

Point::Point(float x,float y)
{
	X = x;
	Y = y;
	ANGLE = 0.0;
	
}
Point::Point(float x,float y,float angle)
{
	X = x;
	Y = y;
	ANGLE = angle;
	
}
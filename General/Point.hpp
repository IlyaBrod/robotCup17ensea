#ifndef CLASS_POINT_DEFINED
#define CLASS_POINT_DEFINED

<<<<<<< HEAD:Point.hpp
#define NULL 0
=======
#include "myMaths.hpp"
>>>>>>> refs/remotes/origin/master:General/Point.hpp

/**
 * Représente un point dans l'escpace 2D.
 * Position X,Y
 * Orientation : angle
 */
class Point
{
public:
	float X;
	float Y;
	float ANGLE;

	Point();
	Point(const float &x, const float &y);
	Point(const float &x, const float &y, const float &angle);
	Point(const Point &p);

	Point& operator=(const Point& p);
	
	float get_Norm();

};

#endif

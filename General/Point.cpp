#include "Point.hpp"

Point::Point(){
	x=0.0;
	y=0.0;
}

Point::Point(const double &_x, const double &_y){
	x = _x;
	y = _y;
}

Point::Point(const Point &p): x(p.x), y(p.y){}

Point& Point::operator=(const Point& p){
	x = p.x ;
	y = p.y ;
	return *this ;
}

double dist(const Point &A, const Point &B){
    return sqrt( (A.x-B.x)*(A.x-B.x)+(A.y-B.y)*(A.y-B.y) );
}

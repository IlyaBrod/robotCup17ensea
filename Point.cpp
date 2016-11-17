#include "Point.hpp"


Point::Point()
{
	x=0;
	y=0;
}


Point::Point(float x,float y,float angle)
{
	this.x = x;
	this.y = y;
	this.angle = angle;
	
}

float Point::getX() {return x;}
float Point::getY() {return y;}
float Point::getAngle() {return angle}


void Point::setX(float x) {this.x=x;}
void Point::setY(float y) {this.y=y;}
void Point::setXY(float x,float y) {this.x=x;this.y=y;}
void Point::setAngle(float angle) {this.angle=angle;}


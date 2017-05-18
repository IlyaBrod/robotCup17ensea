#include "Rectangle.hpp"

Rectangle::Rectangle(double x, double y, double width, double height)
{
	points.push_back(Point(x, y));
	points.push_back(Point(x + width, y));
	points.push_back(Point(x + width, y+height));
	points.push_back(Point(x, y+height));
}
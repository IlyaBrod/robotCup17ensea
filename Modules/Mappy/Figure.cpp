#include "Figure.hpp"

void Figure::addPoint(Point p)
{
	points.push_back(p);
}


double Figure::getX(int i)
{
	if (i >= points.size())
		return points[0].X;
	else
		return points[i].X;
}
double Figure::getY(int i)
{
	if (i >= points.size())
		return points[0].Y;
	else
		return points[i].Y;
}

unsigned int Figure::getSize()
{
	return points.size();
}
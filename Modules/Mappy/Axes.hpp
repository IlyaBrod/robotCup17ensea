#pragma once
#ifndef CLASS_AXES
#define CLASS_AXES

#include <cmath>
#include "Point.hpp"

class Axes : public Point
{
public:
	float ANGLE;
	Axes(double x, double y, float agl);

};
#endif

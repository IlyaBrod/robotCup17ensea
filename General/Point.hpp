#ifndef CLASS_POINT_DEFINED
#define CLASS_POINT_DEFINED

#include <cstddef>
#include <algorithm>
#include <cmath>
/**
 * Représente un point dans l'escpace 2D.
 * Position X,Y
 * Orientation : angle
 */
struct Point{
    public:
        double x;
        double y;

        Point();
        Point(const double &x, const double &y);
        Point(const Point &p);

        Point& operator=(const Point& p);
};

double dist(const Point &A, const Point &B);

#endif

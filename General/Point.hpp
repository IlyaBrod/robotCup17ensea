#ifndef CLASS_POINT_DEFINED
#define CLASS_POINT_DEFINED

<<<<<<< HEAD
#include "myMaths.hpp"


=======
#include <cstddef>
#include <algorithm>
#include <cmath>
>>>>>>> nicolas_dev
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

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

//code de romain >>>
	    float getX () { return x; }
	    float getY () { return y; }

	    float operator*(Point& a) {
	        return calculDistance2 (x, y, a.getX(), a.getY ());
	    }
	    bool operator==(Point& a) {
	        return (x == a.getX () && y == a.getY ());
	    }
	    bool operator!=(Point& a) {
	        return !(*this == a);
	    }
    protected:
    	float calculDistance2(float x1, float y1, float x2, float y2) {
        	return ((x1-x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
    	}
//code de romain <<<

};

double dist(const Point &A, const Point &B);

//code de romain >>>
struct P4 {
    Point p0;
    Point p1;
    Point p2;
    Point p3;
};
typedef struct P4 points4;
//code de romain <<<

#endif

#ifndef POINT_H
#define POINT_H

typedef struct P4 points4;

class point {
public:
    point (float nx, float ny) {
        x = nx;
        y = ny;
    }
    point () { ; }

    float getX () { return x; }
    float getY () { return y; }

    float operator*(point& a) {
        return calculDistance2 (x, y, a.getX(), a.getY ());
    }
    bool operator==(point& a) {
        return (x == a.getX () && y == a.getY ());
    }
    bool operator!=(point& a) {
        return !(*this == a);
    }

protected:
    float calculDistance2(float x1, float y1, float x2, float y2) {
        return ((x1-x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
    }

    float x, y;
};

struct P4 {
    point p0;
    point p1;
    point p2;
    point p3;
};

#endif

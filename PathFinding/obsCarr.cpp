#include "obsCarr.h"

bool obsCarr::getCroisement (point A, point B) {
    point p0 (xcentre - dxtaille, ycentre + dytaille);
    point p1 (xcentre + dxtaille, ycentre + dytaille);
    point p2 (xcentre - dxtaille, ycentre - dytaille);
    point p3 (xcentre + dxtaille, ycentre - dytaille);

    if (CroisementSegment (p0, p3, A, B) || CroisementSegment (p1, p2, A, B) || belongs(A) || belongs(B))
        return true;
    else
        return false;
}

bool obsCarr::getCroisement (float X, float Y, point B) {
    point A (X, Y);
    return getCroisement (A, B);
}

points4 obsCarr::getPoints () {
    return {
        point (xcentre - (dxtaille + MINDISTROBOT), ycentre + (dytaille + MINDISTROBOT)),
        point (xcentre + (dxtaille + MINDISTROBOT), ycentre + (dytaille + MINDISTROBOT)),
        point (xcentre - (dxtaille + MINDISTROBOT), ycentre - (dytaille + MINDISTROBOT)),
        point (xcentre + (dxtaille + MINDISTROBOT), ycentre - (dytaille + MINDISTROBOT)),
    };
}

bool obsCarr::belongs (point& A) {
    return (A.getX () <= xcentre + dxtaille && A.getX () >= xcentre - dxtaille && A.getY () <= ycentre + dytaille && A.getY () >= ycentre - dytaille);
}

#ifndef POINTPARCOURS_H
#define POINTPARCOURS_H
#include "math.h"

#include "controle.h"
#include "point.h"

typedef struct PP4 PointsParc4;

class pointParcours : public point {
public:
    pointParcours (float nx, float ny, pointParcours * npere, point *arr) : point (nx, ny) {
        if (npere != NULL)
            G2 = sqrt(npere->getG2() + calculDistance2 (nx, ny, npere->getX(), npere->getY ()));
        else
            G2 = 0;
        pere = npere;
        H2 = sqrt (calculDistance2 (nx, ny, arr->getX (), arr->getY ()));
    }

    pointParcours (point p, pointParcours * npere, point *arr) : point (p) {
        if (pere != NULL)
            G2 = npere->getG2 () + calculDistance2 (p.getX(), p.getY(), npere->getX (), npere->getY ());
        else
            G2 = 0;
        pere = npere;

        H2 = sqrt(calculDistance2 (p.getX (), p.getY (), arr->getX (), arr->getY ()));
    }

    pointParcours * getPere () { return pere; }

    long double getG2 () { return G2; }
    long double getH2 () { return H2; }
    long double getP2 () { return G2 + H2; }

    bool operator==(pointParcours& a) {
        // Autre version : return (x == a.getX () && y == a.getY () && a.getP2 () == G2 + H2);
        return (x == a.getX () && y == a.getY ());
    }

    bool operator==(point& a) {
        return (x == a.getX () && y == a.getY ());
    }

protected:
    pointParcours * pere;
    long double G2, H2;
};

struct PP4 {
    pointParcours p0;
    pointParcours p1;
    pointParcours p2;
    pointParcours p3;
};

#endif

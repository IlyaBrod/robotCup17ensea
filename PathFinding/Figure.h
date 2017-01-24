#ifndef FIGURE_H
#define FIGURE_H

#include "point.h"

class figure {
public:
    figure(float xc, float yc) {
        xcentre = xc;
        ycentre = yc;
    }

    float getX () { return xcentre; }
    float getY () { return ycentre; }

    bool CroisementSegment (point A1, point A2, point B1, point B2) {
        if (ProdVect (A1, A2, B1, B2) != 0) { // On verifie que les droites ne sont pas parallèles
            if (ProdVect (A1, A2, A1, B2)*ProdVect (A1, A2, A1, B1) <= 0
                && ProdVect (B1, B2, B1, A1)*ProdVect (B1, B2, B1, A2) <= 0) {
                return true;
            }
            else {
                return false;
            }
        }
        else {
            return false;
        }
    }

protected:
    float xcentre, ycentre;

    float ProdVect (float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4) {
        return ((x2 - x1)*(y4 - y3) - (y2 - y1)*(x4 - x3));
    }
    float ProdVect (point A1, point A2, point B1, point B2) {
        return ProdVect (A1.getX(), A1.getY (), A2.getX (), A2.getY (), B1.getX (), B1.getY (), B2.getX (), B2.getY ());
    }
};
#endif

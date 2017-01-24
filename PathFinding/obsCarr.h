#ifndef OBSCARR_H
#define OBSCARR_H

#include "controle.h"
#include "Figure.h"
#include "point.h"

class obsCarr : public figure {
public:
    obsCarr (float xc, float yc, float dxt, float dyt) : figure (xc,yc) {
        dxtaille = dxt;
        dytaille = dyt;
    }

    /* Retourne true si le segment AB croise le rectangle */
    bool getCroisement (point A, point B);
    /* Retourne true si le segment AB croise le rectangle */
    bool getCroisement (float X, float Y, point B);

    /* Retourne 4 Points pas tres loin du rectangle par lesquels peut passer le robot ! */
    points4 getPoints ();
    bool belongs (point& A);

    float getDXT () { return dxtaille; }
    float getDYT () { return dytaille; }

protected:
    float dxtaille, dytaille;
};

#endif

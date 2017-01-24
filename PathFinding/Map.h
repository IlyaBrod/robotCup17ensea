#ifndef MAP_H
#define MAP_H

#include "obsCarr.h"
#include "pointParcours.h"
#include "nVector.h"
#include "controle.h"

class map {
public:
    map ();
    void addObs (obsCarr nobs);
    void FindWay (point dep, point arr);
    nVector<pointParcours>& getParc () { return path; }
    bool& getEnded () { return endedParc; }

protected:
    nVector<obsCarr> obs;
    nVector<pointParcours> path;
    bool endedParc; // Definit s'il existe un chemin parcourable dans le dernier FindWay
};

#endif

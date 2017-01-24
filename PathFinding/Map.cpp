#include "Map.h"

map::map () {
}

void map::addObs (obsCarr nobs) {
    obs.push_back (nobs);
}

void map::FindWay (point dep, point arr) {
    nVector<pointParcours> open;
    nVector<pointParcours> close;
    points4 tmp;
    bool val[4] = {true,true,true,true};
    int os = obs.size ();
    int i, j;
    bool ended=false;   // On teste tous les points ajoutes dans l'open list pour savoir s'il y a intersection avec un obstacle. Ended passe à true quand aucun ne coupe un obstacle.
    endedParc = false;

    pointParcours depP (dep, NULL, &arr);
    int indTMP1=0;  // Le point actuel
    int PointEnding = 0;
    open.push_back (depP);

    while (!ended && !open.empty ()) {
        for (i = 0; i < open.size (); ++i) {
            if (open[i].getP2 () < open[indTMP1].getP2 ())
                indTMP1 = i;
        }

        close.push_first (open[indTMP1]);
        open.erase (indTMP1);
        indTMP1 = 0;

        ended = true;
        for (i = 0; i < os; ++i) {
            if (obs[i].getCroisement (close[indTMP1].getX (), close[indTMP1].getY (), arr)) {
                ended = false;
                tmp = obs[i].getPoints ();

                // On vérifie si le point croise un obstacle
                for (j = 0; j < os; ++j)
                    if (obs[j].getCroisement (tmp.p0, close[indTMP1]))
                        val[0] = false;
                // On vérifie si le point existe déjà dans la liste ouverte
                for (j = 0; j < open.size (); ++j) {
                    if (open[j] == tmp.p0)
                        val[0] = false;
                }
                // On vérifie si le point existe déjà dans la liste fermée
                for (j = 0; j < close.size (); ++j) {
                    if (close[j] == tmp.p0)
                        val[0] = false;
                }
                if (val[0]) {
                    open.push_back (pointParcours (tmp.p0, &close[indTMP1], &arr));
                }

                // On repete l'operation pour le second point
                for (j = 0; j < os; ++j)
                    if (obs[j].getCroisement (tmp.p1, close[indTMP1]))
                        val[1] = false;
                for (j = 0; j < open.size (); ++j) {
                    if (open[j] == tmp.p1)
                        val[1] = false;
                }
                for (j = 0; j < close.size (); ++j) {
                    if (close[j] == tmp.p1)
                        val[1] = false;
                }
                if (val[1]) {
                    open.push_back (pointParcours (tmp.p1, &close[indTMP1], &arr));
                }

                // On répète l'opération pour le troisième point
                for (j = 0; j < os; ++j)
                    if (obs[j].getCroisement (tmp.p2, close[indTMP1]))
                        val[2] = false;
                for (j = 0; j < open.size (); ++j) {
                    if (open[j] == tmp.p2)
                        val[2] = false;
                }
                for (j = 0; j < close.size (); ++j) {
                    if (close[j] == tmp.p2)
                        val[2] = false;
                }
                if (val[2]) {
                    open.push_back (pointParcours (tmp.p2, &close[indTMP1], &arr));
                }

                // On répète l'opération pour le quatrieme point
                for (j = 0; j < os; ++j)
                    if (obs[j].getCroisement (tmp.p3, close[indTMP1]))
                        val[3] = false;
                for (j = 0; j < open.size (); ++j) {
                    if (open[j] == tmp.p3)
                        val[3] = false;
                }
                for (j = 0; j < close.size (); ++j) {
                    if (close[j] == tmp.p3)
                        val[3] = false;
                }
                if (val[3]) {
                    open.push_back (pointParcours (tmp.p3, &close[indTMP1], &arr));
                }

                val[0] = true;
                val[1] = true;
                val[2] = true;
                val[3] = true;

                /*
                if (val[0]) {       // Si le point est accessible et n'existe pas deja
                    open.push_back (pointParcours (tmp.p0, &close[indTMP1], &arr)); // On le rajoute dans la liste ouverte
                    ended = true;   // On suppose que le parcours s'arrete ici
                    for (int a = 0; a < os && ended; ++a)
                        if (obs[a].getCroisement (tmp.p0, arr)) {   // Si on croise un obstacle, le parcours ne s'arrete pas !
                            ended = false;
                            std::cout << "Croisement de " << tmp.p0.getX() << " - " << tmp.p0.getY() << " l'obstacle " << a << std::endl;
                        }
                    if (ended)
                        PointEnding = open.size ();
                }
                if (val[1] && !ended) {
                    ended = true;
                    open.push_back (pointParcours (tmp.p1, &close[indTMP1], &arr));
                    for (int a = 0; a < os && ended; ++a)
                        if (obs[a].getCroisement (tmp.p1, arr)) {
                            ended = false;
                            std::cout << "Croisement de " << tmp.p1.getX () << " - " << tmp.p1.getY () << " l'obstacle " << a << std::endl;
                        }
                    if (ended)
                        PointEnding = open.size ();
                }
                if (val[2] && !ended) {
                    ended = true;
                    open.push_back (pointParcours (tmp.p2, &close[indTMP1], &arr));
                    for (int a = 0; a < os && ended; ++a)
                        if (obs[a].getCroisement (tmp.p2, arr)) {
                            ended = false;
                            std::cout << "Croisement de " << tmp.p2.getX () << " - " << tmp.p2.getY () << " l'obstacle " << a << std::endl;
                        }
                    if (ended)
                        PointEnding = open.size ();
                }
                if (val[3] && !ended) {
                    ended = true;
                    open.push_back (pointParcours (tmp.p3, &close[indTMP1], &arr));
                    for (int a = 0; a < os && ended; ++a)
                        if (obs[a].getCroisement (tmp.p3, arr)) {
                            ended = false;
                            std::cout << "Croisement de " << tmp.p3.getX () << " - " << tmp.p3.getY () << " l'obstacle " << a << std::endl;
                        }
                    if (ended)
                        PointEnding = open.size ();
                }

                val[0] = true;
                val[1] = true;
                val[2] = true;
                val[3] = true;*/
            }
        }
    }

    /* L'algorithme n'est pas bon. Je devrais prendre ici le plus court chemin vers l'arrivée pour ceux qui ne sont pas bloqués, et pas un aléatoire ... */
    if (ended) {
        pointParcours* pente;
        pente = &close[0];
        while (pente != NULL) {
            path.push_first (*pente);
            pente = pente->getPere ();
        }
        path.push_back (pointParcours(arr, &path[path.size()-1], &arr));
        endedParc = true;
    }
}

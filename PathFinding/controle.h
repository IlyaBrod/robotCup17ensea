#ifndef CONTROLE_H
#define CONTROLE_H

/* Points du rectangle :
    0       1

    2       3

    Penser à supprimer MINDISTROBOT et le mettre dans la taille de l'obstacle (on augmentera dxtaille et dytaille de façon adaptée)
    Autre methode d'amelioration : dans la boucle de test de croisement des obstacles, s'il n'y a pas de croisement, mettre ended=true, ca évitera de faire les tests pour tous les points disponibles !
*/

#define NULL 0
#define BATARD 0xCCCCCCCC
#define MINDISTROBOT 1

#endif

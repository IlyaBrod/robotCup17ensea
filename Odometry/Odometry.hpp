#ifndef ODOMETRY_H
#define ODOMETRY_H
 
//#include "DefinesSharps.h"
#include "mbed.h"
#include "../IncludeAll.h"


 
//#define SDevant false
//#define SHomologation false

#define EQUART 243.8
#define DIAMETRE_ROUE 72
#define TICK_P_TOUR 4096

/** Permet la gestion de l'odometrie du robot **/
#define DEBUG_ODO
class Odometry
{
private:
    CodR* leftCod;
    CodR* rightCod;
    
    float X,Y,ANGLE_Rad;

public:
    Odometry(CodR* left,CodR* right);

    float getX();
    float getY();
    float getAngle();
    
    /**
     *  Actualise la positon du robot
     * @param avance True si avance en avant
     */
    void update_I(bool avance);

    

};
 
#endif
 

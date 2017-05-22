#include "Odometry.hpp"
#include "../General/myMaths.hpp"
#include <cmath>
#include "../IncludeAll.h"

Odometry::Odometry(CodR* left,CodR* right)
{
        leftCod = left;
        rightCod = right;
        #ifdef DEBUG_ODO
        GeneralItem::DEBUG_PC.printf("\n\rDEBUG_ODO ACTIVE\n\r");
        #endif //DEBUG_ODO
        rightCod->reset();
        leftCod->reset();
        X = 0;
        Y = 0;
        ANGLE_Rad = 0;

}


float Odometry::getX()
{
    return X;
}


float Odometry::getY()
{
    return Y;
}


float Odometry::getAngle()
{
    return ANGLE_Rad;
}

//ticks d'integration
#define TIKS_INTEGR 100
void Odometry::update_I(bool avance)
{
    //float D1 = (((float)leftCod.get())*PI*DIAMETRE_ROUE)/(1.0*TICK_P_TOUR);
    float D1 = (((float)leftCod->get())*PI*DIAMETRE_ROUE)/(1.0*TICK_P_TOUR);
    float D2 = (((float)rightCod->get())*PI*DIAMETRE_ROUE)/(1.0*TICK_P_TOUR);
   
    float d_inst = 0;
    
    
    float theta = 0;
    float R1 = 0;
    float Coef_avance = -1;
    if (D1 >= 0 && D2 >=0)
    {
        Coef_avance = 1;
    }
    else if (D1 <= 0 && D2 <= 0)
    {
        D1 = -D1;
        D2 = -D2;
        Coef_avance = -1;
    }
    else if (D1 <= 0 && D2 >=0)
    {
        Coef_avance = 1;
    }
    else if (D2 <= 0 && D1 >=0)
    {
        Coef_avance = -1;
    }


    if (D1==D2)
        {
            X += Coef_avance*D1*cos(ANGLE_Rad);
            Y += Coef_avance*D1*sin(ANGLE_Rad);
        }
    else if (D1 < D2)
        {
              theta = Coef_avance*(D2 - D1)/EQUART;
            R1 = Coef_avance*D1/theta;
            R1 += EQUART/2;
            ANGLE_Rad += theta/2;
            d_inst = 2*R1*sin(theta/2);
            
            X += cos(ANGLE_Rad)*d_inst;
            Y += sin(ANGLE_Rad)*d_inst;
            ANGLE_Rad += theta/2;
            

        }
    else if (D2 < D1)
        {
            theta = Coef_avance*(D1 - D2)/EQUART;
            R1 = Coef_avance*D2/theta;
            R1 += EQUART/2;
            ANGLE_Rad -= Coef_avance*theta/2;
            d_inst = 2*R1*sin(theta/2);
            
            X += cos(ANGLE_Rad)*d_inst;
            Y += sin(ANGLE_Rad)*d_inst;
          
            ANGLE_Rad -= Coef_avance*theta/2;
        }
        #ifdef DEBUG_ODO
      
        GeneralItem::DEBUG_PC.printf("X =%f  Y =%f Angle =%f\n\r", X,Y,360*ANGLE_Rad/(2*PI));
        GeneralItem::DEBUG_PC.printf("000000000000000000000000000\n\r");
        GeneralItem::DEBUG_PC.printf("D1 = %f, D2 = %f \n\r", D1, D2);
        GeneralItem::DEBUG_PC.printf("R1 = %f, Theta = %f \n\r", R1, theta);
        #endif //DEBUG_ODO
}
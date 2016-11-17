#include "Balise.hpp"


Balise::Balise(float baliseRadius)
{
	this.baliseRadius = baliseRadius;
}


float Balise::triangulate(float angle1, float angle2, float angle3)
{



	return 0.0;
}


float Balise::duoangulate(float angle1,float angle2)
{
	float r1= calc_Dist_From_Balise(angle1);
	float r2= calc_Dist_From_Balise(angle2);


	return 0.0;
}



float calc_Dist_From_Balise(float angle)
{
	float teta = 180-angle;
	float dist = baliseRadius*sin(teta/2)/tan(angle/2)+baliseRadius*cos(teta/2) ;
	return dist;
}


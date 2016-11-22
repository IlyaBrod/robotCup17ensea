#include "Balise.hpp"


Balise::Balise(float baliseRadius)
{
	this.baliseRadius = baliseRadius;
}


Point Balise::triangulate(float angle1, float angle2, float angle3)
{
	Point Poi_Robot();

	float r1= calc_Dist_From_Balise(angle1);
	float r2= calc_Dist_From_Balise(angle2);
	float r3= calc_Dist_From_Balise(angle3);



	return Poi_Robot;
}


Point Balise::duoangulate(float angle1,float angle2)
{
	Point Poi_Robot();
	float r1= calc_Dist_From_Balise(angle1);
	float r2= calc_Dist_From_Balise(angle2);


	return Poi_Robot;
}



float calc_Dist_From_Balise(float angle)
{
	float teta = 180-angle;
	float dist = baliseRadius*sin(teta/2)/tan(angle/2)+baliseRadius*cos(teta/2) ;
	return dist;
}


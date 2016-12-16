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



float Balise::calc_Dist_From_Balise(float angle)
{
	float teta = 180-angle;
	float dist = baliseRadius*sin(teta/2)/tan(angle/2)+baliseRadius*cos(teta/2) ;
	return dist;
}


float Balise::get_Orientation(float db2, float db1, float angle)
{
	float kb2,kb1;
	
	kb1 = acos((-(db2*db2 - db1*db1 - B2B1*B2B1)) / (2*db1*db1))*180/PI;
	kb2 = CORNER_B2-(180-angle-kb1);
	
	return 360-(180-ANGLE_B2-kb2);
	
}




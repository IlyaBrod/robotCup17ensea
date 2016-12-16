#include "Balise.hpp"


Balise::Balise(float baliseRadius)
{
	this.baliseRadius = baliseRadius;
	this.mode = 0;
}

void Balise::setMode(int newMode)
{
	if(newMode>=0 && newMode<=2) {this.mode = newMode;}
}

double Balise::triACalc(double r1,double r2,double n1, double n2)
{
	return 0.5*(r1*r1-r2*r2+n2-n1);
}


Point Balise::triangulate_From_Dist(float r1, float r2, float r3)
{
	Point Loc();

	double a12 = triACalc(r1,r2,P1_NORM2,P2_NORM2);
	double a13 = triACalc(r1,r3,P1_NORM2,P3_NORM2);

	double Y = (a13-D13X*a12/D12X)/(D13Y-D13Y*D12Y/D12X);
	double X = (a12-D12Y*Y)/D12X;

	Loc.X = X;
	Loc.Y = Y;
	
	return Loc;
}


Point Balise::duoangulate_1(float angle1,float angle2)
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





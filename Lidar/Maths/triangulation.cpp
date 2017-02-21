#include "triangulation.hpp"

Point* triangulate(std::vector<Balise>* data,Settings &config)
{
	Point* location = new Point();
	
	if(config.mode==0)
	{

	}
	else
	{	
		std::vector<int>* selection;
		
		if(config.ennemyBeacon==true) 					// ADD TEAM COLOR CHANGE
		{
			selection -> push_back(0);
			selection -> push_back(1);
			selection -> push_back(2);
			int* idx = find_Index_ID(data,selection);
			float* xy = triangulate_3D(compute_dist((data->at(idx[0])).DELTA),compute_dist((data->at(idx[1])).DELTA),compute_dist((data->at(idx[2])).DELTA));
			location -> X = xy[0];
			location -> Y = xy[1];
		}
		else
		{
			selection -> push_back(0);
			selection -> push_back(2);
			selection -> push_back(4);
			int* idx = find_Index_ID(data,selection);
			float* xy = triangulate_3D(compute_dist((data->at(idx[0])).DELTA),compute_dist((data->at(idx[1])).DELTA),compute_dist((data->at(idx[2])).DELTA));
			location -> X = xy[0];
			location -> Y = xy[1];
		}
		
	}

	return location;
}



float compute_dist(float angle)
{
	float alpha = toRad(angle/2);
	float teta = toRad(180-angle);
	return RADIUS_B*sin(teta/2)/tan(alpha) + RADIUS_B*cos(teta/2);
}

void compute_beacon_dist(Balise &b)
{
	b.DIST = compute_dist(b.DELTA);
}


 float triACalc(float r1,float r2,float n1, float n2)
{
	return 0.5*(r1*r1-r2*r2+n2-n1);
}

float* triangulate_3D(float r1,float r2,float r3)
{
	float* vector = new float[2];
	float a12 = triACalc(r1,r2,P1_NORM2,P2_NORM2);
	float a13 = triACalc(r1,r3,P1_NORM2,P3_NORM2);

	vector[1] = (a13-D13X*a12/D12X)/(D13Y-D13Y*D12Y/D12X); //Y
	vector[0] = (a12-D12Y*vector[1])/D12X; //X

	return vector;
}


float* triangulate_2D(Balise &b1,Balise &b2)
{
	float* vector = new float[2];


	/*
	orientation = 180 - angle caractéristique du terrain (45° dans exemple) - A2
	A2  =

	Angle bot right triangle = acos( (-(R2B2 R2B2 - R2B1 R2B1 - B2B1 B2B1)) / (2R2B1 B2B1) )


	*/

	return vector;
}
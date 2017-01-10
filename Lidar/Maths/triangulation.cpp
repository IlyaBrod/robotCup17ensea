#include "triangulation.hpp"



Point* triangulate(double* anglesArray,int mode)
{
	Point* loc = new Point();
	
	return loc;
}



float compute_dist(float angle)
{
	float alpha = toRad(angle/2);
	float teta = toRad(180-angle);
	return RADIUS_B*sin(teta/2)/tan(alpha) + RADIUS_B*cos(teta/2);
}

void compute_dist(Balise &b)
{
	b.DIST = compute_dist(b.DELTA);
}

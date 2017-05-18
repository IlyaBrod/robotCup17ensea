#include "Mappy.hpp"

Mappy::Mappy() : robot(0,0,0)
{

}

void Mappy::moveRobot(double x, double y, float agl)
{
	robot.ANGLE = agl;
	robot.X = x;
	robot.Y = y;
}


bool Mappy::check(int sensorID, double dist)
{
	bool state = false;
	double xc = 0;
	double yc = 0;
	double distc = 99999;
	double dist_pre = 999;
	double alpha1 = 0;

	//Ajust angle using sensorID
	float theta = robot.ANGLE;
	switch (sensorID)
	{
	case 0:
		break;
	case 1:
		theta -= 90;
		break;
	case 2:
		theta += 90;
		break;
	}
	
	//Modulo 360°
	if (theta > theta)
		theta -= 360;
	printf("Theta = %f \n",theta);
	double alpha = tan(theta/180*PI); //droite directrice du robot
	printf("Robot orientation Alpha : %4.2f \n", alpha);

	// => ANALYSE, for each object on the map
	printf("Figure number : %d\n", map.size());
	for (unsigned int idMap = 0; idMap < map.size(); idMap++)
	{
		printf("Figure %d => %d points\n", idMap,map[idMap].getSize());

		for (unsigned int pt = 0; pt < map[idMap].getSize(); pt++)
		{
			printf("Point %d X:%f Y: %f \n", pt, map[idMap].getX(pt), map[idMap].getY(pt));
			
			//1) Compute intersection
			alpha1 = map[idMap].getY(pt + 1) - map[idMap].getY(pt) / (map[idMap].getX(pt + 1) - map[idMap].getX(pt));
			
			//case of horizontal line
			if (map[idMap].getY(pt + 1) == map[idMap].getY(pt))
			{
				xc = (map[idMap].getY(pt) - robot.Y) / alpha;
				yc = map[idMap].getY(pt);
			}
			else if (map[idMap].getX(pt+1) == map[idMap].getX(pt)) //case of vertical line
			{
				xc = map[idMap].getX(pt);
				yc = alpha*xc + robot.Y;
			}
			else
			{
				xc = -(robot.Y - map[idMap].getY(pt)) / (alpha - alpha1);
				yc = (alpha * map[idMap].getY(pt) - alpha1*robot.Y) / (alpha - alpha1);
			}
			
			//2) Limit to segment
			if (xc > maxi(map[idMap].getX(pt), map[idMap].getX(pt + 1))) continue;
			else if (xc < mini(map[idMap].getX(pt), map[idMap].getX(pt + 1))) continue;
			else if (yc > maxi(map[idMap].getY(pt), map[idMap].getY(pt + 1))) continue;
			else if (yc < mini(map[idMap].getY(pt), map[idMap].getY(pt + 1))) continue;
			else printf("\t xc: %f yc:%f \n\n", xc, yc);
			

			//3) Check distance limit + check minimal distance
			dist_pre = sqrt((xc - robot.X)*(xc - robot.X) + (yc - robot.Y)*(yc - robot.Y));
			printf("\tDist %f \n", dist_pre);
			if (dist < dist_pre + ERROR && dist > dist_pre - ERROR)
				return false;

		}
	}
	
	return true;
}

#pragma once
#ifndef CLASS_MAPPY
#define CLASS_MAPPY
#define PI 3.14159265
#define ERROR 50 // 50mm max distance variance from detection and the map


#include <cmath>
#include <stdio.h>
#include "Qmath.hpp"
#include "Map.hpp"
#include "Axes.hpp"

/**
 * Global class of all computing.
 * Find if a detected obstacle is an object or a robot.
 * Sensor IDs : 
 *				Front 0
 *		Left 2			Right 1
 */
class Mappy : public Map
{
private:
	Axes robot; //robot location
public:
	Mappy();

	/**
	 * Move the robot
	 * @param x
	 * @param y
	 * @param agl Orientation
	 */
	void moveRobot(double x, double y, float agl);

	/**
	 * Check the type of obstacle detected
	 * @param sensorID Give the location of the sensor (face)
	 * @param dist Distance detected by the sensor
	 * @return False if it's a wall, True if it's a robot
	 */
	bool check(int sensorID,double dist);

};
#endif // !CLASS_MAPPY

#ifndef TRIANG_HPP
#define TRIANG_HPP

#define P1_NORM2 0.0
#define P2_NORM2 2500.0
#define P3_NORM2 5000.0
#define D12X 50.0
#define D12Y 0.0
#define D13X 50.0
#define D13Y 50.0



/**
 * Map characteristics 
 *                        TOP beacon
 *   MID beacon
 *                        BOT beacon
 */
#define DMID_BOT 50
#define DMID_TOP 50
#define DTOP_BOT 50


#include "../../General/Point.hpp"
#include "BALISE_CONFIG.hpp"
#include "Balise.hpp"
#include <cmath>
#include <vector>
#include "../General/myMaths.hpp"
#include "Settings.hpp"


/**
 * Return a point representating the location and orientation of the robot.\n
 * Modes :\n
 * -1 : can't compute correct data
 * 0 : 2 beacons
 * 1 : 3 beacons with distances method
 * @param data Table of all beacons
 * @param config Setteings of the MapAnalyser
 * @return Point* with calculated X, Y and ANGLE (orientation)
 */
Point* triangulate(std::vector<Balise>* data,Settings &config);

/**
 * Compute the distance between a beacon to the robot.
 * @param angle Angle of observation [degree]
 * @return distance in cm
 */
float compute_dist(float angle);

/**
 * Compute the distance for a beacon.
 * @param &b beacon reference
 */
void compute_beacon_dist(Balise &b);

/**
 * Compute special value for triangulisation
 * @param r1 Distance beacon 1
 * @param r2 Distance beacon 2
 * @param n1 Norm vector 1
 * @pram n2 Norm vector 2
 * @return Special constant
 */
 float triACalc(float r1,float r2,float n1, float n2);

/**
 * Triangulate with 3 distances.
 * @param r1 Disatance 1
 * @param r2 Distance 2
 * @param r3 Distance 3
 * @return float[2] : [X,Y]
 */
float* triangulate_3D(float r1,float r2,float r3);


/**
 * Triangulate with 2 beacons.
 * @param beacon 1
 * @param beacon 2
 * @return float[2] : [X,Y]
 */
float* triangulate_2D(Balise &b1,Balise &b2);


#endif

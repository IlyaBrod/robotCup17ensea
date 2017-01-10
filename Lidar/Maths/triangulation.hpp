#include "../../General/Point.hpp"
#include "BALISE_CONFIG.hpp"
#include "Balise.hpp"
#include <cmath>
#include "../General/myMaths.hpp"
/**
 * Return a point representating the location and orientation of the robot.\n
 * Modes :\n
 * -1 : can't compute correct data
 * 0 : 2 beacons
 * 1 : 3 beacons with angles method
 * 2 : 3 beacons with distances method
 * @param anglesArray Table of all angular values
 * @param mode Mode of triangulisation
 */
Point* triangulate(double* anglesArray,int mode);

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



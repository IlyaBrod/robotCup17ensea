#include "Point.hpp"


/**
 * Return a point representating the location and orientation of the robot.\n
 * Modes :\n
 * 0 : 2 beacons
 * 1 : 3 beacons with angles method
 * 2 : 3 beacons with distances method
 * @param anglesArray Table of all angular values
 * @param mode Mode of triangulisation
 */
Point* triangulate(double* anglesArray,int mode);



#ifndef CLASS_MAPANALYZER_HPP
#define CLASS_MAPaNALYZER

#include <vector>
#include "../../General/myMaths.hpp"
#include "Balise.hpp"

#define EPSILON 0.11
#define MOVE_EPSILON 10

/**
 * Analyse the scanned map, to define the most efficient location
 * calculating method.\n
 * Check the number of beacons (if the opponnent have some.\n
 * Give the starting side.\n
 */
class MapAnalyser
{
	
	private:
		
		bool loopOnce;
		bool ennemyBeacon;
		
		int mode;
		
		std::vector<Balise> anglesArray_prev;
		std::vector<Balise> anglesArray_curr;
		std::vector<float> anglesArray_raw;
		
		//True if the scanning cycles ended by a high value
		bool endByTop;
		/**
		 * Correct the detections errors,
		 * construct a beacons map, detect number of beacons which 
		 * gives a viable data.
		 */
		void correct_Data();
		void set_Mode();

	public:
	
		MapAnalyser();
		
		/**
		 * Add an angle to the system.
		 * @param angle represents a variation of sensor data
		 */
		void add_Angle(double angle);
		
		/**
		 * Get the number of valid beacons
		 * @return number
		 */
		int count();
		
		/**
		 * Get the adapted mode of triangulisation.
		 * @return mode
		 */
		int get_Mode();
		
		/**
		 * Get the cleaned angle array
		 * @return vector of values
		 */
		std::vector<double>* get_Data();
		
		
		/**
		 * Give the initial location of the robot on the map.
		 * @return 1 if the robot is yellow, 2 if blue, 0 if error.
		 */ 
		char get_Side();
		
		
		/**
		 * To execute after a 360° round of the sensor.
		 */
		void update();
		
};


#endif

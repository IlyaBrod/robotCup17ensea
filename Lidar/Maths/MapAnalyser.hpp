#ifndef CLASS_MAPANALYZER_HPP
#define CLASS_MAPaNALYZER

#include <vector>
#include "../../General/myMaths.hpp"
#include "Balise.hpp"

#define EPSILON 0.11
#define MOVE_EPSILON 10

typedef enum{YELLOW,BLUE} TeamColor;

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
		TeamColor side;
		
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

		/** #1
		 * Configure the number of beacons after the first scan round
		 */
		void detect_ennemy();
		
		/**
		 * Detect the color side of the robot
		 */
		void detect_side();

		/**
		 * Scan to run after the first round
		 */
		void first_Scan();
		
		/** #2
		 * Convert raw to balise assuming no errors
		 * (grouping 2 per 2 angles), hold the save IDs
		 */
		void direct_convert();

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
		 * Get the orientation of the robot (angle from Y ground axis)
		 * @return angle [degree]
		 */
		float get_Orientation();
		
		/**
		 * Get the cleaned angle array
		 * @return vector of values
		 */
		std::vector<Balise>* get_Data();
		
		
		/**
		 * Give the initial location of the robot on the map.
		 * @return 1 if the robot is yellow, 2 if blue, 0 if error.
		 */ 
		char get_Side();
		
		
};


#endif

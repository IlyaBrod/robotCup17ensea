#ifndef CLASS_MAPANALYZER_HPP
#define CLASS_MAPANALYZER_HPP

#include <vector>
#include "../../General/myMaths.hpp"
#include "Balise.hpp"
#include "triangulation.hpp"

#define EPSILON 0.11
#define MOVE_EPSILON 10
#define TRACK_EPSILON 10.0

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
		
		std::vector<Balise> anglesArray_prev; //PREV
		std::vector<Balise> anglesArray_curr; //CURR
		std::vector<float> anglesArray_raw; //RAW
		float* initAngles;
		
		//True if the scanning cycles ended by a high value
		bool endByTop;
		
		/**
		 * Correct the detections errors,
		 * Construct a beacons map, detect number of beacons which 
		 * gives a viable data.
		 */
		void correct_Data();
		
		/**
		 * Generate adapted mode of triangulisation
		 */
		void set_Mode();

		/** #1
		 * Configure the number of beacons after the first scan round.
		 * Initialize the IDs of all beacons.
		 */
		void detect_ennemy();
		
		/**
		 * Detect the color side of the robot. Assuming that the DIST
		 * was compute before.
		 */
		void detect_side();

		/**
		 * Scan to run after the first round
		 */
		void first_Scan();
		
		/** #2
		 * Convert raw to balise assuming no errors
		 * (grouping 2 per 2 angles), hold the save IDs.\n
		 * Compute distances.
		 */
		void direct_convert();

		/**
		 * Need to be executed when the 0° is send.\n
		 * Apply error correction, convert RAW to CURR.\n
		 * Refresh computing mode.\n
		 */
		 void refresh();

		/**
		 * Get the nearest beacon present in PREV.
		 * Only in activated beacons. With a distance limit defined by
		 * TRACK_EPSILON
		 * @param &b beacon
		 * @param eps=TRACK_EPSILON (maximim deviation angle [degree])
		 * @return index of the nearest beacon, -1 if error.
		 */
		 int track(const Balise &b,float eps = TRACK_EPSILON);

	public:
	
		MapAnalyser();
		
		/**
		 * Add an angle to the system. After RAISE or FALL\n
		 * WARNING : Add an 0° angle when the sensor did a round. 
		 * @param angle represents a variation of sensor data [degree]
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

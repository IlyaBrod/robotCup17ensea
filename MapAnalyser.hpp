#ifndef CLASS_MAPANALYZER_HPP
#define CLASS_MAPaNALYZER

#include <vector>

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
		
		int number;
		int mode;
		
		std::vector<double> anglesArray_prev;
		std::vector<double> anglesArray_curr;
		std::vector<double> anglesArray_raw;
		
		void correct_Data();
		
	public:
	
		MapAnalyser();
		
		/**
		 * Add an angle to the system.
		 * @param angle
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

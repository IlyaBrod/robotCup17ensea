#ifndef CLASS_MAPANALYZER_HPP
#define CLASS_MAPaNALYZER


/**
 * Analyse the scanned map, to define the most efficient location
 * calculating method.\n
 * Check the number of beacons (if the opponnent have some.\n
 * Give the starting side.\n
 */
class MapAnalyser
{
	
	private:
		char loop;
		bool loopOnce;
	
		bool ennemyBeacon;
		double* beaconArray;
		
	public:
		MapAnalyser();
		
		/**
		 * To execute when a new scanning loop is did.
		 */
		void loop();
		
		/**
		 * Give the initial location of the robot on the map.
		 * @return 1 if the robot is yellow, 2 if blue, 0 if error.
		 */
		char get_Side();
		
		
	
	
};


#endif

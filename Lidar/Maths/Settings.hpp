#ifndef CLASS_SETTINGS_HPP
#define CLASS_SETTINGS_HPP

typedef enum{YELLOW,BLUE} TeamColor;

/**
 * Store important date for triangulisation
 * Easy argument.
 */
class Settings
{
 	public:
		Settings();
		bool ennemyBeacon;
		TeamColor side;
		int mode;
        float orientation;
};

#endif
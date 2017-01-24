#ifndef GENERALITEM_H
#define GENERALITEM_H
/**
 * generalItem contien des constantes et des objet nessessaire au bon fonctionement du robot
 * des timers
 * des constantes
 */

#include "../mbed.h"
#include "../Lidar/Sensor/PwmStepMotor.h"

class GeneralItem
{
public :
	static Timer sinceInitUsTimer;

	static void initGeneralItem();
};



#endif //GENERALITEM_H

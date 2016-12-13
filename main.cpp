/* Fichier principal du robot.
 * Controleur : NUCLEO_F411RE
 *
 */

//hello
#include "IncludeAll.h"


//DigitalOut myled(LED1);
//Point p(5,6,10);
PwmStepMotor(D6);

int main() {
	GeneralItem::initGeneralItem();
    while(1) {
        //myled = 1;
        //wait(0.2);
        //myled = 0;
        //wait(0.2);
    }
}



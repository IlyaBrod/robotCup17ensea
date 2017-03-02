/* Fichier principal du robot.
 * Controleur : NUCLEO_F411RE
 * Les fonction des tests et commande ne doivent pas être placées ici.
 * Le code principal des robots est placé dans les méthodes "run".
 */

#include "IncludeAll.h"
#include "Robot/RobotPrincipal.hpp"

DigitalOut runningLed(LED1);
RobotPrincipal ilGo;

int main() {

	GeneralItem::initGeneralItem();
	ilGo.run();
    
    while(1) {

        runningLed = 1;
        wait(1);
        runningLed = 0;
    }
}



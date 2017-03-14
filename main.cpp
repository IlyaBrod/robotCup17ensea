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
        wait_ms(10);
        GeneralItem::DEBUG_PC.printf("timer raw : %ud \n\r", GeneralItem::sinceInitUsTimer.read_us());
        wait_ms(10);
    }
}



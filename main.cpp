/* Fichier principal du robot.
 * Controleur : NUCLEO_F411RE
 * Les fonction des tests et commande ne doivent pas être placées ici.
 * Le code principal des robots est placé dans les méthodes "run".
 */

#include "IncludeAll.h"
#include "Robot/RobotPrincipal.hpp"

DigitalOut runningLed(LED1);
RobotPrincipal ilGo;
Lidar test(D6,D7);

int main() {

	GeneralItem::initGeneralItem();
	//ilGo.run();
    #ifdef DEBUG_SPY_LIDAR
    GeneralItem::DEBUG_PC.printf("1");
    GeneralItem::DEBUG_PC.printf("2");
    GeneralItem::DEBUG_PC.printf("3");
    GeneralItem::DEBUG_PC.printf("\n");
    GeneralItem::DEBUG_PC.printf("lets go in ");
    GeneralItem::DEBUG_PC.printf("LIDAR debug mode\n\r");
    wait_ms(100);
    #endif //DEBUG_SPY_LIDAR
    test.start();
    
    while(1) {

        
        
         }
}



/* Fichier principal du robot.
 * Controleur : NUCLEO_F411RE
 * Les fonction des tests et commande ne doivent pas être placées ici.
 * Le code principal des robots est placé dans les méthodes "run".
 */

#include "IncludeAll.h"
#include "Robot/RobotPrincipal.hpp"

DigitalOut runningLed(LED1);
RobotPrincipal ilGo;
PwmStepMotor test;

int main() {

	GeneralItem::initGeneralItem();
	//ilGo.run();
    test.start();
    
    while(1) {
        test.pause();
        test.printAngle();
        wait_ms(1000);
        test.start();
        wait_ms(10);
        
        
         }
}



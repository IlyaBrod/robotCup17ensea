/* Fichier principal du robot.
 * Controleur : NUCLEO_F411RE
 *
 */

//hello
#include "IncludeAll.h"


DigitalOut myled(LED1);
//Point p(5,6,10);
//PwmStepMotor mypwm(D5);
PwmOut myPwm(D6);

int main() {
	//GeneralItem::initGeneralItem();
	//mypwm.start();
	myPwm.period_ms(20);
	myPwm.write(0.5);
    while(1) {
        myled = 1;
        wait(1);
        myled = 0;
        wait(1);
    }
}



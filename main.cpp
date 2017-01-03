/* Fichier principal du robot.
 * Controleur : NUCLEO_F411RE
 *
 */

//hello
#include "IncludeAll.h"


DigitalOut myled(LED1);
//Point p(5,6,10);
PwmStepMotor myPwm2(PB_4);
PwmOut myPwm(PB_10);

int main() {
	GeneralItem::initGeneralItem();
	myPwm2.start();
	myPwm.period_us(20);
	myPwm.write(0.5);
    while(1) {
        myled = 1;
        wait(1);
        myled = 0;
        wait(1);
    }
}



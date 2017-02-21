/* Fichier principal du robot.
 * Controleur : NUCLEO_F411RE
 *
 */

//hello
#include "IncludeAll.h"
Serial pc(USBTX, USBRX);
DigitalOut Tled(D8);

DigitalOut myled(LED1);
//Point p(5,6,10);
//Lidar balise();
//PwmOut myPwm(PB_10);

int main() {
	pc.baud(9600);
    //GeneralItem::initGeneralItem();
	//myPwm2.start();
	//myPwm.period_us(20);
	//myPwm.write(0.5);
    while(1) {
        pc.printf("\rAfficahge\r");
        myled = 0;
        Tled = 1;
        wait(1);
        Tled = 0;
        myled = 1;
    }
}



/* Fichier principal du robot.
 * Controleur : NUCLEO_F411RE
 *
 */

//hello
#include "IncludeAll.h"


DigitalOut myled(LED1);
//Point p(5,6,10);
PwmStepMotor balise(D6);
//PwmOut myPwm(PB_10);
Serial pc(USBTX,USBRX);

int main() {
    pc.baud(9600);
	GeneralItem::initGeneralItem();
    balise.set(10000,0.5);
	
    balise.set(100,0.7,4048);
    balise.start();
    
    wait (1);

    balise.stop();
    
    while(1) {
        
        myled = 1;
        wait(1);
        myled = 0;
        wait(1);
        
        pc.printf("\n\r%f",balise.readAngle());
        //pc.printf("test\n\r");
    }
}



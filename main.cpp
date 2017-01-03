/* Fichier principal du robot.
 * Controleur : NUCLEO_F411RE
 *
 */

//hello
#include "mbed.h"
#include "Point.hpp"


DigitalOut myled(LED1);
Point p(5,6,10);

int main() {
    while(1) {
        myled = 1;
        wait(0.2);
        myled = 0;
        wait(0.2);
    }
}



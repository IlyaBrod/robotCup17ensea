/* Fichier principal du robot.
 * Controleur : NUCLEO_F411RE
 * Les fonction des tests et commande ne doivent pas être placées ici.
 * Le code principal des robots est placé dans les méthodes "run".
 */

#include "IncludeAll.h"
#include "Robot/timerbot1.hpp"
//#define DEBUG


//DigitalOut runningLed(LED1);
//DigitalIn button(USER_BUTTON) ;
//RobotPrincipal ilGo;
//Lidar test(D6,D7);
//CodR codeur1(D8,D9);
timerbot1 robot;



int main() {

	GeneralItem::initGeneralItem();
    Hcsr04 cap1(PA_5,PC_0);
    wait_ms(30);
    //Hcsr04 cap2(PC_6,PC_1);
    wait_ms(30);
    //Hcsr04 cap3(PA_11,PB_0);
    wait_ms(30);
    //Hcsr04 cap4(PA_12,PA_4);
    wait_ms(30);
    robot.associate_Hcsr04(&cap1,&cap1,&cap1,&cap1);
    #ifdef DEBUG
    GeneralItem::DEBUG_PC.printf("debug\n\r");
    wait_ms(300);
    #endif
    


    wait_ms(1000);
    
    robot.avant(5);
    #ifdef DEBUG
    GeneralItem::DEBUG_PC.printf("avant\n\r");
    wait_ms(300);
    #endif
    robot.arriere(5);
    #ifdef DEBUG
    GeneralItem::DEBUG_PC.printf("arriere\n\r");
    #endif
    robot.droite(90);
    robot.gauche(90);





    //test moteur
    /*
    *DigitalOut d7(D7);
    *DigitalOut d8(D8);
    *PwmOut d9(D9);

    *d7 = 1;
    *d8 = 0;
    *
    *d9.period_ms(2);
    *d9.write(0.5);
    *timerbot1 robot1;
    */

    //CodR codeur1(D8,D9);
    //CodR codeur2(D12,D13);
    //Odometry odo(&codeur1,&codeur2);
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
    //test.start();
    
  


    while(1) {
        
        //codeur1.get();
        //codeur2.get();
        //odo.update_I(true);
        //    wait_ms(1000);
         }
}



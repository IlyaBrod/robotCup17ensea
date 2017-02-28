/* objet robot 
 * contien toute les composantes d'un robot
 */

 #include "IncludeAll.h"
 
 
 class Robot 
 {
	 private :
		Lidar lidar;
		
	 
	 public :
		Robot(PinName pinMotor = PB_4, PinName pinSensor = PA_4);
	 
	 
 };

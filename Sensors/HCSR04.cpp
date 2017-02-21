#include "HCSR04.hpp"

HCSR04::HCSR04(PinName trig, PinName echo): _trig(trig), _echo(_echo){
	_en = false ;
	state = false ;
	_echo.disable_irq();
	_echo.rise(this, &HCSR04::startCount);
	_echo.fall(this, &HCSR04::stopCount);
}

void HCSR04::enable(bool en){
	_en = en ;

	if(en==true){
		_echo.enable_irq();
		startTrig();
	}else{
		_echo.disable_irq();
	}
}

void HCSR04::startTrig(){
	if(state == false){
		state = true ;
		_trig = 1 ;
		timeTrig.attach(this, &HCSR04::stopTrig, 0.00001);
	}
}

void HCSR04::stopTrig(){
	_trig = 0 ;
}

void HCSR04::startCount(){
	timeEcho.start();
}

void HCSR04::stopCount(){
	timeEcho.stop();
	dist = timeEcho.read_us()/58 ;
	timeEcho.reset();
	state = false ;
	
	if(_en){
		startTrig();
	}
}
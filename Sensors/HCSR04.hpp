#ifndef HCSR04_HPP
#define HCSR04_HPP

#include "mbed.h"

class HCSR04{
	protected :
		bool _en ;
		bool state ;		//false = free, true = in Use
		float dist ;
		DigitalOut _trig ;
		InterruptIn _echo ;
		Timeout timeTrig ;
		Timer timeEcho ;

		void stopTrig();
		void startCount();
		void stopCount();

	public :
		HCSR04(PinName trig, PinName echo);

		float read()const{return dist ;}
		bool isEnabled()const{return _en ;}

		void enable(bool en);

		void startTrig();
};

#endif
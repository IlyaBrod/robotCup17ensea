#ifndef CAPTEURBALISE_H
#define CAPTEURBALISE_H


class CapteurBalise: public PwmStepMotor
{
private :
		
		InterruptIn pinIn;
	
public :
	CapteurBalise (PinName pwmOut, PinName digitalIn);
	actInteruptionUp ();
	actInteruptionDown ();
}

#endif //CAPTEURBALISE_H

#ifndef CLASS_SERVO
#define CLASS_SERVO

#include "../mbed.h"

#define DEFAULT_MIN 0.045
#define DEFAULT_MAX 0.13

/**
 * Classe de gestion de servo moteur.
 * Possibilité d'ajuster les bornes pour adapter au moteur.
 */
class Servo
{
    private:
        float min=DEFAULT_MIN;
        float max=DEFAULT_MAX;

        PwmOut pin;
        void setDuty(float alpha);

    public:
        Servo(PinName p);

        /**
         * Go to a position
         * @param deg Angle in degree
         */
        void write(int deg);
        
        /**
         * Stoppe le moteur. 
         * Evite le problème des valeurs d'angles trop grandes.
         */
        void stop();

        /**
         * Amélioration des bornes du servo.
         * Les paramètres sont Valeur à ajouter aux valeurs par défault.
         * @param value1
         * @param value2
         */
         void setRange(float value1, float value2);
         void resetRange();

};




#endif

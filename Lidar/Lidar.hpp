#ifndef CLASS_LIDAR_HPP
#define CLASS_LIDAR_HPP

#include "Sensor/PwmStepMotor.h"
#include "Maths/MapAnalyser.hpp"

#include "mbed.h"

//debug psy Lidar : cmmenter pourdesactiver
#define DEBUG_SPY_LIDAR


class Lidar : public PwmStepMotor 
{
    private:
        MapAnalyser analyser;
        InterruptIn sensor;
       

        /**
         * Permet de relier le getAngle de PwmStepMotor
         * au addAngle de MapAnalyser
         */
        void link();

    public:
        /**
         * Initialisation with specific pin names
         * @param pinMotor Pin of stepmotor
         * @param pinSensor Pin of infrared sensor
        */
        Lidar(PinName pinMotor = D6, PinName pinSensor=D7);

        /**
         * Affiche les différentes caractéristiques du système
         */
         void print();
         void print_Angles();

         void print_Orientation();
         void print_Side();
         void print_Beacons();
         void print_Mode();
         void print_Count();

         void start();
         void pause();



};




#endif
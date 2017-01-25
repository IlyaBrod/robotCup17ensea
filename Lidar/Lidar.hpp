#ifndef CLASS_LIDAR_HPP
#define CLASS_LIDAR_HPP

#include "Sensor/PwmStepMotor.h"
#include "Maths/MapAnalyser.hpp"
#include "mbed.h"

class Lidar : private PwmStepMotor 
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
        Lidar();
        /**
         * Initialisation with specific pin names
         * @param pinMotor Pin of stepmotor
         * @param pinSensor Pin of infrared sensor
        */
        Lidar(PinName pinMotor, PinName pinSensor);


};




#endif
#include "Robot.hpp"

Robot::Robot(PinName lidarpinMotor, PinName lidarpinSensor): lidar(lidarpinMotor,lidarpinSensor)
{
	lidar.set(100,0.7,4048);

}

void Robot::run()
{
    lidar.start();
    wait(1);
    lidar.stop();
    lidar.print_Angles();
}


void Robot::move(float x, float y)
{

}
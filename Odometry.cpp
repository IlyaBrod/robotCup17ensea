#include "Odometry.h"
 
// M1 = Moteur droit, M2 = Moteur gauche
 
Odometry::Odometry(double diameter_right, double diameter_left, double v, uint16_t quadrature, RoboClaw &rc) : roboclaw(rc)
{
    m_v = v;
    m_distPerTick_left = diameter_left*PI/quadrature;
    m_distPerTick_right = diameter_right*PI/quadrature;
 
    roboclaw.ForwardM1(0);
    roboclaw.ForwardM2(0);
    roboclaw.ResetEnc();
    // Erreur autorisée sur le déplacement en angle
    erreur_ang = 0.01;
 
    m_pulses_right = 0;
    m_pulses_left = 0;
    pos_prog = 0;
    wait_ms(100);
}
 
void Odometry::setPos(double x, double y, double theta)
{
    this->x = x;
    this->y = y;
    this->theta = theta;
}
void Odometry::getEnc()
{
    logger.printf("EncM1 : %d\tEncM2 : %d\n\r", roboclaw.ReadEncM1(), roboclaw.ReadEncM2());
}
 
void Odometry::setX(double x)
{
    this->x = x;
}
 
void Odometry::setY(double y)
{
    this->y = y;
}
 
void Odometry::setTheta(double theta)
{
    this->theta = theta;
}
 
void Odometry::update_odo(void)
{
    int32_t roboclawENCM1 = roboclaw.ReadEncM1(); 
    int32_t roboclawENCM2 = roboclaw.ReadEncM2();
    int32_t delta_right = roboclawENCM1 - m_pulses_right;
    m_pulses_right = roboclawENCM1;
    int32_t delta_left = roboclawENCM2 - m_pulses_left;
    m_pulses_left = roboclawENCM2;
    
    double deltaS = (m_distPerTick_left*delta_left + m_distPerTick_right*delta_right)*C / 2.0f;
    double deltaTheta = (m_distPerTick_left*delta_left - m_distPerTick_right*delta_right)*C / m_v;
 
    /*double R = deltaS/deltaTheta;
 
    double xO = x - R*sin(theta);
    double yO = y + R*cos(theta);
 
    theta += deltaTheta;
 
    if(deltaTheta == 0) {
        x = x + deltaS*cos(theta);
        y = y + deltaS*sin(theta);
    }
    else {
        x = xO + R*sin(theta);
        y = yO - R*cos(theta);
    }*/
    
    
    
    double dx = deltaS*cos(theta+deltaTheta/2);
    double dy = deltaS*sin(theta+deltaTheta/2);
    x += dx;
    y += dy;
    
    theta += deltaTheta;
    while(theta > PI) theta -= 2*PI;
    while(theta <= -PI) theta += 2*PI;
}
 
void Odometry::GotoXY(double x_goal, double y_goal)
{
    double theta_ = atan2(y_goal-y, x_goal-x);
    double dist_ = sqrt(carre(x_goal-x)+carre(y_goal-y));
    logger.printf("Dist : %3.2f\tTheta : %3.2f\n\r", dist_, theta_*180/PI);
    GotoThet(theta_);
    logger.printf("J'ai fais theta je suis pas trop un fdp\n\r");
    GotoDist(dist_);
    logger.printf("J'ai fais Dist je suis pas trop un fdp\n\r");
}
 
void Odometry::GotoXYT(double x_goal, double y_goal, double theta_goal)
{
    double theta_ = atan2(y_goal-y, x_goal-x);
    double dist_ = sqrt(carre(x_goal-x)+carre(y_goal-y));
    logger.printf("Dist : %3.2f\tTheta : %3.2f\n\r", dist_, theta_*180/PI);
    GotoThet(theta_);
    GotoDist(dist_);
    GotoThet(theta_goal);
}
 
void Odometry::GotoThet(double theta_)
{
    //pos_prog++;
    //logger.printf("Theta : %3.2f\n\r", theta_*180/PI);
    //arrived = false;
    int32_t distance_ticks_left;
    int32_t distance_ticks_right;
 
    int32_t pos_initiale_right = m_pulses_right, pos_initiale_left = m_pulses_left;
 
    // Le calcul d'erreur est bon (testé), tu peux le vérifier par dessin
    double erreur_theta = theta_ - getTheta();
 
    while(erreur_theta >= PI) erreur_theta -= 2*PI;
    while(erreur_theta < -PI) erreur_theta += 2*PI;
    
    logger.printf("ET : %3.2f\n\r", erreur_theta*180/PI);
    
    if(erreur_theta < 0) {
        distance_ticks_left = (int32_t) pos_initiale_left + (erreur_theta*m_v/2)/m_distPerTick_left;
        distance_ticks_right = (int32_t) pos_initiale_right - (erreur_theta*m_v/2)/m_distPerTick_right;
    } else {
        distance_ticks_left = (int32_t) pos_initiale_left + (erreur_theta*m_v/2)/m_distPerTick_left;
        distance_ticks_right = (int32_t) pos_initiale_right - (erreur_theta*m_v/2)/m_distPerTick_right;
    }
 
    //logger.printf("TV %3.2f\tTh %3.2f\tET %3.2f\n\r",theta_*180/PI,getTheta()*180/PI,erreur_theta*180/PI);
    //logger.printf("X : %3.2f\tY : %3.2f\tTheta : %3.2f\n\r", getX(), getY(), getTheta()*180/PI);
    //logger.printf("M1 %6d\tM2 %6d\n\r",distance_ticks_right, distance_ticks_left);
 
    roboclaw.SpeedAccelDeccelPositionM1M2(accel_angle, vitesse_angle, deccel_angle, distance_ticks_right, accel_angle, vitesse_angle, deccel_angle, distance_ticks_left, 1);
 
    //logger.printf("IniR:%6d\tDistR:%6d\tIniL:%6d\tDistL:%6d\n\r", pos_initiale_right, distance_ticks_right, pos_initiale_left, distance_ticks_left);
 
    while(abs(m_pulses_right - distance_ticks_right) >= 1 && abs(m_pulses_left - distance_ticks_left) >= 1) {   
        if (SDevant && SHomologation) {
            roboclaw.SpeedAccelM1M2(accel_dista, 0, 0);
            while(1);
        }
    }
    //logger.printf ("[Thet] %d\t%d\n\r", m_pulses_right - distance_ticks_right, m_pulses_left - distance_ticks_left); 
    //logger.printf("%6d\t%6d\t%6d\t%6d\t%6d\n\r",m_pulses_right - pos_initiale_right, distance_ticks_right, m_pulses_left - pos_initiale_left, distance_ticks_left);
    
    wait(0.4);
    theta = theta_;
    //arrived = true;
    //logger.printf("arrivey %d\n\r",pos_prog);
}
 
void Odometry::GotoDist(double distance)
{
    //pos_prog++;
    //logger.printf("Dist : %3.2f\n\r", distance);
    //arrived = false;
 
    int32_t pos_initiale_right = m_pulses_right, pos_initiale_left = m_pulses_left;
 
    int32_t distance_ticks_right = (int32_t) distance/m_distPerTick_right + pos_initiale_right;
    int32_t distance_ticks_left = (int32_t) distance/m_distPerTick_left + pos_initiale_left;
    logger.printf("Je suis un fdp a l'envoi d'une commande 1 !\n\r");
    if (distance >= 0)
        roboclaw.SpeedAccelDeccelPositionM1M2(accel_dista, vitesse_dista, deccel_dista, distance_ticks_right, accel_dista, vitesse_dista, deccel_dista, distance_ticks_left, 1);
    else
        roboclaw.SpeedAccelDeccelPositionM1M2(accel_dista, -vitesse_dista, deccel_dista, distance_ticks_right, accel_dista, -vitesse_dista, deccel_dista, distance_ticks_left, 1);   
    logger.printf("J'suis un fdp 2\n\r");
    //logger.printf("IniR:%6d\tDistR:%6d\tIniL:%6d\tDistL:%6d\n\r", pos_initiale_right, distance_ticks_right, pos_initiale_left, distance_ticks_left);
    
    while(abs(m_pulses_right - distance_ticks_right) >= 1 && abs(m_pulses_left - distance_ticks_left) >= 1) //logger.printf("PR:%6d\tIR:%6d\tDR:%6d\tPL:%6d\tIL:%6d\tDL:%6d\n\r",m_pulses_right, pos_initiale_right, distance_ticks_right, m_pulses_left, pos_initiale_left, distance_ticks_left);
    {  
        if (SDevant && SHomologation) {
            roboclaw.SpeedAccelM1M2(accel_dista, 0, 0);
            while(1) ;
        }
    }
    wait(0.4);
    //logger.printf("arrivey %d\n\r",pos_prog);
    //logger.printf("X : %3.2f\tY : %3.2f\tTheta : %3.2f\n\r", getX(), getY(), getTheta()*180/PI);
}
 
void Odometry::TestEntraxe(int i) {
    int32_t distance_ticks_left;
    int32_t distance_ticks_right;
 
    int32_t pos_initiale_right = m_pulses_right, pos_initiale_left = m_pulses_left;
 
    double erreur_theta = 2*PI*i - getTheta();
    if(erreur_theta < 0) {
        distance_ticks_left = (int32_t) pos_initiale_left + (erreur_theta*m_v/2)/m_distPerTick_left;
        distance_ticks_right = (int32_t) pos_initiale_right - (erreur_theta*m_v/2)/m_distPerTick_right;
    } else {
        distance_ticks_left = (int32_t) pos_initiale_left + (erreur_theta*m_v/2)/m_distPerTick_left;
        distance_ticks_right = (int32_t) pos_initiale_right - (erreur_theta*m_v/2)/m_distPerTick_right;
    }
    
    roboclaw.SpeedAccelDeccelPositionM1M2(accel_angle, vitesse_angle, deccel_angle, distance_ticks_right, accel_angle, vitesse_angle, deccel_angle, distance_ticks_left, 1);
    
    while((m_pulses_right != distance_ticks_right)&&(m_pulses_left != distance_ticks_left))
        logger.printf ("[Dist] %d\t%d\n\r", m_pulses_right - distance_ticks_right, m_pulses_left - distance_ticks_left);
        
    wait(0.4);
}
 
void Odometry::Forward(float i) {    
    int32_t pos_initiale_right = m_pulses_right, pos_initiale_left = m_pulses_left;
 
    int32_t distance_ticks_right = (int32_t) i/m_distPerTick_right + pos_initiale_right;
    int32_t distance_ticks_left = (int32_t) i/m_distPerTick_left + pos_initiale_left;
 
    roboclaw.SpeedAccelDeccelPositionM1M2(accel_dista, vitesse_dista, deccel_dista, distance_ticks_right, accel_dista, vitesse_dista, deccel_dista, distance_ticks_left, 1);
 
    //logger.printf("IniR:%6d\tDistR:%6d\tIniL:%6d\tDistL:%6d\n\r", pos_initiale_right, distance_ticks_right, pos_initiale_left, distance_ticks_left);
    
    while((m_pulses_right != distance_ticks_right)&&(m_pulses_left != distance_ticks_left)); //logger.printf("PR:%6d\tIR:%6d\tDR:%6d\tPL:%6d\tIL:%6d\tDL:%6d\n\r",m_pulses_right, pos_initiale_right, distance_ticks_right, m_pulses_left, pos_initiale_left, distance_ticks_left);
    wait(0.4);
}
            
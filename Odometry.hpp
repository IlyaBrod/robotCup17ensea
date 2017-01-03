#ifndef ODOMETRY_H
#define ODOMETRY_H
 
#include "DefinesSharps.h"
#include "mbed.h"
#include "../RoboClaw/RoboClaw.h"
 
#define PI 3.1415926535897932384626433832795
#define C 1.0
 
/* Vitesse d'acceleration d'angle reduite de 8000->4000 */
#define accel_angle 12000
#define vitesse_angle 10000
#define deccel_angle 12000
 
#define accel_dista 12000
#define vitesse_dista 12000
#define deccel_dista 12000
 
<<<<<<< HEAD
/* Si le robot parcourt un trop grand angle, il diminue l'entraxe, sinon l'augmenter */
=======
/* Si le robot parcourt un trop grand angle, il diminuer l'entraxe, sinon l'augmenter */
>>>>>>> refs/remotes/origin/nicolas_dev
#define ENTRAXE 243.8
 
/*
*   Author : Benjamin Bertelone, reworked by Simon Emarre
*/
 
extern Serial logger;
 
/** Permet la gestion de l'odometrie du robot **/
class Odometry
{
public:
    /** Constructeur standard
    * @param diameter_right Definit le diametre de la roue droite
    * @param diameter_left Definit le diametre de la roue gauche
    * @param v Definit l'entraxe du robot
    * @param rc Definit une reference vers l'objet permettant l'asserv des moteurs
    * @note Cet objet doit etre initialise en amont
    */
    Odometry(double diameter_right, double diameter_left, double v, uint16_t quadrature, RoboClaw &rc);
 
    /** Demande au robot d'effectuer un certain nombre de tour sur lui même */
    void TestEntraxe(int i);
 
    /** Demande au robot d'effectuer un déplacement sur l'avant. Voir si l'on peut enlever la correction PID */
    void Forward(float i);
 
    /** Les fonctions suivantes permettent de reinitialiser les valeurs de position de l'odometrie.
    */
    void setPos(double x, double y, double theta);
    void setX(double x);
    void setY(double y);
    void setTheta(double theta);
 
    /** Les fonctions suivantes permettent de deplacer le robot vers une position ou un angle voulu
    */
    void GotoXY(double x_goal, double y_goal);
    void GotoXYT(double x_goal, double y_goal, double theta_goal);
    void GotoThet(double theta_);
    void GotoDist(double distance);
 
    double getX() {
        return x;
    }
    double getY() {
        return y;
    }
    double getTheta() {
        return theta;   // ]-PI;PI]
    }
    double getTheta_(double x, double y);
 
    double abs_d(double x) {
        if(x<0) return -x;
        else return x;
    }
 
    /* Les fonction suivantes sont actuellement inutilisables, elles pourraient buguer en cas d'utilisation. */
 
    double getVitLeft() {
        return m_vitLeft;
    }
    double getVitRight() {
        return m_vitRight;
    }
 
    double getDistLeft() {
        return m_distLeft;
    }
    double getDistRight() {
        return m_distRight;
    }
 
    void setDistLeft(double dist) {
        m_distLeft = dist;
    }
    void setDistRight(double dist) {
        m_distRight = dist;
    }
 
    double calcul_distance(double x, double y, double theta_goal);
 
    int32_t getPulsesLeft(void) {
        return m_pulses_left;
    }
    int32_t getPulsesRight(void) {
        return m_pulses_right;
    }
    double carre(double a) {
        return a*a;
    }
    
    void getEnc();
    
    /** La fonction retourne vraie quand le robot atteint l'angle voulu avec une marge d'erreur definie par la fonction
    * @param theta_ valeur de l'angle devant etre atteint
    */
    bool isArrived(void) {return arrived;}
    /** Permet de mettre à jour les valeurs de l'odometrie
    */
    void update_odo(void);
 
private:
    RoboClaw &roboclaw;
    int32_t m_pulses_left;
    int32_t m_pulses_right;
    uint8_t pos_prog;
    double x, y, theta;
    double m_vitLeft, m_vitRight;
    double m_distLeft, m_distRight;
 
    double m_distPerTick_left, m_distPerTick_right, m_v;
 
    double erreur_ang;
    bool arrived;
};
 
#endif
 
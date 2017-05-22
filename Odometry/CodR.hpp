#ifndef CODR_HPP
#define CODR_HPP


#include "../mbed.h"

#define CEBUG_CODR

class CodR 
{
    public:
        enum state{Au = 0,Bu,Ad,Bd,Nop};
        
        CodR(PinName BrocheA = PB_8, PinName BrocheB = PB_9);
       //0 -> count_codeur;
        void reset();
        // return count_codeur
        //0 -> count_codeur;
        int get();
        //true -> vers l'avant
        //void set_direction();
        static int nb_codeur;

    protected:
        
        int num_codeur;
        InterruptIn brocheA;
        InterruptIn brocheB;
        state etat;
        
        int count_codeur;
        
        void Aup();
        void Bup();
        void Adown();
        void Bdown();

        //void int_increment_codeur(void);

};






#endif // CODR_HPP
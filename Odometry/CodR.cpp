#include "CodR.hpp"
#include "../IncludeAll.h"
int CodR::nb_codeur = 0;

CodR::CodR(PinName BrocheA, PinName BrocheB) : brocheA(BrocheA),brocheB(BrocheB)
{
    brocheA.rise(callback(this,&CodR::Aup));
    brocheB.rise(callback(this,&CodR::Bup));
    brocheA.fall(callback(this,&CodR::Adown));
    brocheB.fall(callback(this,&CodR::Bdown));
    nb_codeur++;
    num_codeur = nb_codeur;
    etat = Nop;
}

void CodR::reset()
{
    count_codeur = 0;// ça ne marche pas
}

/*
void CodR::int_increment_codeur()
{
    count_codeur++;
}*/

void CodR::Aup()
{
    if (etat == Bu)
        count_codeur--;
    else if (etat == Bd)
        count_codeur++;
    etat = Au;
}
void CodR::Bup()
{
        if (etat == Ad)
        count_codeur--;
    else if (etat == Au)
        count_codeur++;
    etat = Bu;
}
void CodR::Adown()
{
    if (etat == Bd)
        count_codeur--;
    else if (etat == Bu)
        count_codeur++;
    etat = Ad;
}
void CodR::Bdown()
{
        if (etat == Au)
        count_codeur--;
    else if (etat == Ad)
        count_codeur++;
    etat = Bd;
}




int CodR::get()
{
    //#ifdef DEBUG_CODR
        GeneralItem::DEBUG_PC.printf("codeur%d = %d\n\r",num_codeur ,count_codeur);
    //#endif //DEBUG_CODR
    int a = count_codeur;
    count_codeur = 0;
    return a;
  
}



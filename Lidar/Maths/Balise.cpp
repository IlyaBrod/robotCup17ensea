#include "Balise.hpp"

Balise::Balise() : Point()
{
	ID = 0;
	DELTA=0;
}

Balise::Balise(int id) : Point()
{
	ID=id;
	DELTA=0;
}

Balise::Balise(int x,int y,int id) : Point(x,y)
{
	ID = id;
	DELTA=0;
}


void Balise::activate()
{
	active=true;
}


void Balise::desactivate()
{
	active=false;
}

bool Balise::get_State()
{
	return active;
}

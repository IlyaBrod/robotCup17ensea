#include "Balise.hpp"

Balise::Balise() : Point()
{
	ID = 0;
	DELTA=0;
	DIST=0;
	active=true;
}

Balise::Balise(int id) : Point()
{
	ID=id;
	DELTA=0;
	DIST=0;
	active=true;
}

Balise::Balise(int x,int y,int id) : Point(x,y)
{
	ID = id;
	DELTA=0;
	DIST=0;
	active=true;
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


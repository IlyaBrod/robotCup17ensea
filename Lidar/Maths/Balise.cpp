#include "Balise.hpp"

Balise::Balise() : Point()
{
	ID = 0;
}

Balise::Balise(int x,int y,int id) : Point(x,y)
{
	ID = id;
}


void Balise::activate()
{
	active=true;
}

void Balise::desactivate()
{
	active=false;
}

bool Balise::getState()
{
	return active;
}


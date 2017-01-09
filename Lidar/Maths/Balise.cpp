#include "Balise.hpp"

Balise::Balise() : Point()
{
	ID = 0;
	delta=0;
}

Balise::Balise(int x,int y,int id) : Point(x,y)
{
	ID = id;
	delta=0;
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

float Balise::get_Delta()
{
	return delta;
}

void Balise::set_Delta(float d)
{
	delta=d;
}


#include "Balise.hpp"

Balise::Balise(int x,int y,int id) : Point(x,y)
{
	ID = id;
}

void move_Near(&std::vector<Balise> baliseArray)
{	
	for(unsigned int i=0;i<baliseArray.size();i++)
	{
			diff.push_back( baliseArray.at(baliseArray.begin()+i) );
	}
}

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

int* find_Index_ID(std::vector<Balise>* data,std::vector<int>* IDs)
{
	int* result = new int[IDs -> size()];
	int idx=0;

	while((unsigned int)idx<IDs -> size())
	{
		for(unsigned int i=0;i<data->size();i++)
		{
			int id = (data -> at(i)).ID;
			if(id==IDs->at(idx))
			{
				result[idx] = i;
				idx++;
				break;
			}
		}
	}

	return result;

}
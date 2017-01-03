#include "MapAnalyser.hpp"

MapAnalyser::MapAnalyser()
{	
	loopOnce=false;
	ennemyBeacon=false;
	
	int number = 0;
	int mode = 1;
}

void MapAnalyser::add_Angle(double angle)
{
	anglesArray_raw.push_back(angle);
}

int MapAnalyser::count()
{
	return number;
}

int MapAnalyser::get_Mode()
{
	return mode;
}

std::vector<double>* MapAnalyser::get_Data()
{
	return &anglesArray_curr;
}

char MapAnalyser::get_Side()
{
	if(loopOnce==false)
	{
		return 0;
	}
	else
	{
		if(ennemyBeacon==false)
		{
			if(anglesArray_curr[0]<anglesArray_curr[1] && anglesArray_curr[1]<anglesArray_curr[2])
			{
				return 2;
			}
			else
			{
				return 1;
			}
		}
		else
		{
			if(anglesArray_curr[2]<100)
			{
				return 2;
			}
			else
			{
				return 1;
			}
		}
	}
}



void MapAnalyser::update()
{
	anglesArray_prev = anglesArray_curr;
	anglesArray_curr.clear();
	loopOnce=true;
	correct_Data();
	
}

void MapAnalyser::correct_Data()
{
	
	
}

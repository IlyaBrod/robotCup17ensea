#include "MapAnalyser.hpp"

double abs(double);

double abs(double val)
{
	if(val<0)
	{
		return -val;
	}
	else
	{
		return val;
	}
	
}

MapAnalyser::MapAnalyser()
{	
	loopOnce=false;
	ennemyBeacon=false;
	
	mode = 1;
}

void MapAnalyser::add_Angle(double angle)
{
	anglesArray_raw.push_back(angle);
}

int MapAnalyser::count()
{
	return (int)anglesArray_curr.size();
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
	
	double toNext;
	double expectedError;
	
	std::vector<int> toErase;
	
	if(anglesArray_raw.size()!=0)
	{
		//ERROR TYP 1 : Check beacons middle mask
		for(unsigned int i=0;i<anglesArray_raw.size();i+=4)
		{
			toNext = anglesArray_raw.at(i+3)-anglesArray_raw.at(i+4);
			expectedError = anglesArray_raw.at(i+2)-anglesArray_raw.at(i+1);
			
			if(expectedError< toNext-toNext/3)
			{
				//correct the error
				anglesArray_curr.push_back(anglesArray_raw.at(i+3)-anglesArray_raw.at(i));
			}
			else
			{
				//add witout error correction
				anglesArray_curr.push_back(anglesArray_raw.at(i+1)-anglesArray_raw.at(i));
				anglesArray_curr.push_back(anglesArray_raw.at(i+3)-anglesArray_raw.at(i+2));
			}
		}
			
		//ERROR TYP 2 : Check beacons extremity masks
		
		if(anglesArray_prev.size()!=0)
		{	//equal size case
			if(anglesArray_prev.size()==anglesArray_curr.size())
			{
				for(unsigned int j=0;j<=anglesArray_curr.size();j++)
				{
					if(abs(anglesArray_curr.at(j)-anglesArray_prev.at(j))>MOVE_EPSILON)
					{
						toErase.push_back(j);
					}
				}
			}
			//diff size case
			else
			{
				
				
			}
			
		if(toErase.size()!=0)
		{
			for(unsigned int x=0;x<=toErase.size();x++)
			{
				anglesArray_curr.erase(anglesArray_curr.begin()+toErase.at(x));
			}
		}	
		
		}	
			
			
		//ERROR TYP 3 : extra small angles
		
		toErase.clear();
		for(unsigned int i=0;i<anglesArray_curr.size();i++)
		{
			if(anglesArray_curr.at(i)<EPSILON)
					{
						toErase.push_back(i);
					}
		}
		
		if(toErase.size()!=0)
		{
			for(unsigned int x=0;x<=toErase.size();x++)
			{
				anglesArray_curr.erase(anglesArray_curr.begin()+toErase.at(x));//toErase.at(x)
			}
		}
		
		
		
	}
}


void MapAnalyser::set_Mode()
{
	int nbr = count();
	if(nbr<2)
	{
		mode=-1;
	}
	else if(nbr==2)
	{
		mode=1;
	}
	else
	{
		mode=2;
	}
}

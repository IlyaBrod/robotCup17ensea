#include "MapAnalyser.hpp"

// 																 PUBLIC

MapAnalyser::MapAnalyser()
{	
	for(int i=0;i<6;i++)
	{
		anglesArray_curr.push_back(Balise());
		anglesArray_curr.at(i).ID=i;
	}
	
	
	loopOnce=false;
	ennemyBeacon=false;
	endByTop=false;
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

std::vector<Balise>* MapAnalyser::get_Data()
{
	return &anglesArray_curr;
}

char MapAnalyser::get_Side()
{
	return side;
}

float MapAnalyser::get_Orientation()
{
	for(unsigned int i;i< anglesArray_curr.size();i++)
	{
		
	}
	
	return 0.0;
}

// 																 PRIVATE

void MapAnalyser::first_Scan()
{
	
	
}

void MapAnalyser::direct_convert()
{
	int j=0;
	for(unsigned int i=0;i<anglesArray_raw.size();i+=2)
	{
		anglesArray_curr.at(j).ANGLE = anglesArray_raw.at(i);
		anglesArray_curr.at(j).DELTA = anglesArray_raw.at(i+1)-anglesArray_raw.at(i);
		j++;
	}
	
	
}

void MapAnalyser::detect_side()
{
	
}

void MapAnalyser::detect_ennemy()
{
	if(anglesArray_raw.size()>6)
	{	
		for(int i=0;i<6;i++)
		{
			anglesArray_curr.push_back(Balise(i));	
		}
		
		ennemyBeacon=true;
	}
	else
	{
		for(int i=0;i<3;i++)
		{
			anglesArray_curr.push_back(Balise(i));	
		}
		ennemyBeacon=false;
	}
}

void MapAnalyser::correct_Data()
{
	/*
	double part1,part2;
	bool state = endByTop;
	std::vector<int> toErase;
	
	if(anglesArray_raw.size()!=0)
	{
		//ERROR TYPE 0 : Reset zone on the beacon
		
		
		
		//ERROR TYP 1 : Check beacons middle mask
		for(unsigned int i=0;i<anglesArray_raw.size();i++)
		{
			//invert state
			if(state==true)
			{
				state=false;
			}
			else
			{
				state=true;
			}
			
			
			if(endByTop==false)
			{
				part1 = anglesArray_raw.at(i+1)-anglesArray_raw.at(i);
				part2 = anglesArray_raw.at(i+2)-anglesArray_raw.at(i+1);
			}
			else
			{
				
			}
			
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
		
		
		
	}*/
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


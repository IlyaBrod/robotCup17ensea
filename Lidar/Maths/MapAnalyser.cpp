#include "MapAnalyser.hpp"

// 																 PUBLIC

MapAnalyser::MapAnalyser()
{	
	for(int i=0;i<6;i++)
	{
		anglesArray_curr.push_back(Balise());
		anglesArray_curr.at(i).ID=i;
	}
	
	initAngles = new float[6];
	loopOnce=false;
	ennemyBeacon=false;
	endByTop=false;
	mode = 1;
}

void MapAnalyser::add_Angle(double angle)
{
	if(angle==0)
	{
		refresh();
	}
	else
	{
		anglesArray_raw.push_back(angle);
	}
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
	float summ=0;
	for(unsigned int i; i<anglesArray_curr.size();i++)
	{
		summ+=anglesArray_curr.at(i).ANGLE-initAngles[anglesArray_curr.at(i).ID];
	}
	
	return summ/anglesArray_curr.size();
}

// 																 PRIVATE

void MapAnalyser::first_Scan()
{
	//detect ennemyes beacons
	detect_ennemy();
		
	raw_To_Curr();
	
	//Save initials angles to get orientation
	for(unsigned int i;i<anglesArray_curr.size();i++)
	{
		initAngles[i]=anglesArray_curr.at(i).ANGLE;
	}
	
	
	//detect side
	detect_side();
}

void MapAnalyser::raw_To_Curr(const int param)
{
	if(param==1) //DIRECT CONVERT
	{
		//convert
		int j=0;
		for(unsigned int i=0;i<anglesArray_raw.size();i+=2)
		{
			anglesArray_curr.at(j).ANGLE = anglesArray_raw.at(i);
			anglesArray_curr.at(j).DELTA = anglesArray_raw.at(i+1)-anglesArray_raw.at(i);
			j++;
		}
	}
	else //CONVERT WITH CORRECTION
	{

	}

	//OTHER TASKS
	//	Compute dists
	for(unsigned int i=0;i<anglesArray_curr.size();i++)
	{
		compute_beacon_dist(anglesArray_curr.at(i));
	}


}

void MapAnalyser::detect_side()
{
		if(anglesArray_curr.at(1).DIST<anglesArray_curr.at(2).DIST)
		{// d1 < d2
			if(ennemyBeacon==true)
			{
				side=YELLOW;
			}
			else
			{
				side=BLUE;
			
			}
		}
		else
		{// d1 > d2
			if(ennemyBeacon==true)
			{
				side=BLUE;
			}
			else
			{
				side=YELLOW;
			}
		}

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

/*
void MapAnalyser::correct_Data()
{
	
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
		
		
		
	}
}*/

void MapAnalyser::auto_Mode()
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

void MapAnalyser::refresh()
{
	std::vector<Balise> interList;
	int idx;
	
	//Copy CURR to PREV
	anglesArray_prev.clear();
	anglesArray_prev=anglesArray_curr;
	
	
	//From RAW to CURR
	raw_To_Curr(1);
	
	//Reorganise data
	if(anglesArray_curr.size()>anglesArray_prev.size())
	{ //there is more beacons than before, track beacons
		
	}
	else if(anglesArray_curr.size()<anglesArray_prev.size())
	{ //there is less beacons than before
		interList = anglesArray_prev;
		
		for(unsigned int i;i<anglesArray_curr.size();i++)
		{
			idx=track(anglesArray_curr.at(i));
			
			if(idx!=-1)
			{
				anglesArray_curr.at(i).ID = anglesArray_prev.at(idx).ID;
				interList.erase(interList.begin()+idx);
			}
		
		}
		
		
	}
	else
	{
		//same
	}
	
	anglesArray_raw.clear();
}

int MapAnalyser::track(const Balise &b,float eps)
{
	float min= anglesArray_prev.at(0).ANGLE;
	unsigned int idx=10; //random defaut values
	
	for(unsigned int i;i<anglesArray_prev.size();i++)
	{	
		if(anglesArray_prev.at(i).get_State()==true)
		{
			float diff = abs(anglesArray_prev.at(i).ANGLE-b.ANGLE);
			if(min>diff && diff<eps)
			{
				min=diff;
				idx=i;
			}
		}
	}
	
	if(idx==10)
	{
		return -1;
	}
	else
	{
		return (int)idx;
	}
	
}

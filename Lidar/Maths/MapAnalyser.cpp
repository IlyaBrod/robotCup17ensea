#include "MapAnalyser.hpp"

// 																 PUBLIC

MapAnalyser::MapAnalyser()
{	
	for(int i=0;i<6;i++)
	{
		anglesArray_curr.push_back(Balise());
		anglesArray_curr[i].ID=i;
	}
	
	initAngles = new float[6];
	loopOnce=false;
}

void MapAnalyser::add_Angle(double angle)
{
	//Why not : delet RAW +-1 ?
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
	int taille=0;
	for(unsigned int i=0;i<anglesArray_curr.size();i++)
	{
		if(anglesArray_curr[i].get_State())
		{
			taille++;
		}
	}
	return taille;
}

int MapAnalyser::get_Mode()
{
	return config.mode;
}

std::vector<Balise>* MapAnalyser::get_Data()
{
	return &anglesArray_curr;
}

char MapAnalyser::get_Side()
{
	return config.side;
}

float MapAnalyser::get_Orientation()
{
	float summ=0;
	for(unsigned int i=0; i<anglesArray_curr.size();i++)
	{
		if(anglesArray_curr[i].get_State())
		{
			summ+=anglesArray_curr[i].ANGLE-initAngles[anglesArray_curr[i].ID];
		}	
	}
	
	return (float)summ/count();
}

// 																 PRIVATE

void MapAnalyser::first_Scan()
{
	//detect ennemyes beacons
	detect_Ennemy();

	//delete unused beacons
	if(config.ennemyBeacon==false)
	{
		for(int i=0;i<3;i++)
		{
			anglesArray_raw.erase(anglesArray_raw.end());
			anglesArray_prev.erase(anglesArray_prev.end());
			anglesArray_curr.erase(anglesArray_curr.end());
		}
	}

	raw_To_Curr();
	
	//Save initials angles to get orientation
	for(unsigned int i=0;i<anglesArray_curr.size();i++)
	{
		initAngles[i]=anglesArray_curr[i].ANGLE;
	}
	
	//detect side
	detect_Side();

	anglesArray_raw.clear();
}

void MapAnalyser::raw_To_Curr(const int param)
{

	//ERROR TYPE 0 : Reset zone on the beacon
	//-> Remove the 2 elements of RAW data corresponding to reset Zone
	anglesArray_raw.erase(anglesArray_raw.begin());
	anglesArray_raw.erase(anglesArray_raw.begin()+anglesArray_raw.size()-1);

	if(param==1) //DIRECT CONVERT
	{
		//convert
		int j=0;
		for(unsigned int i=0;i<anglesArray_raw.size();i+=2)
		{
			anglesArray_curr[j].ANGLE = anglesArray_raw[i];
			anglesArray_curr[j].DELTA = anglesArray_raw[i+1]-anglesArray_raw[i];
			j++;
		}
	}
	else //CONVERT WITH CORRECTION
	{
		//ERROR TYP 1 : Check beacons middle mask
		float step0,step1,step2;
		int bIdx=0;
		int Idx=0;


		for(unsigned int i=0;i<anglesArray_curr.size();i++)
		{
			anglesArray_curr[i].desactivate();
		}			

		while((unsigned int)Idx<anglesArray_raw.size()-1)
		{
			step0 = anglesArray_raw[Idx+1] - anglesArray_raw[Idx];
			step1 = anglesArray_raw[Idx+2] - anglesArray_raw[Idx+1];
			step2 = anglesArray_raw[Idx+3] - anglesArray_raw[Idx+2];
			
			if(step1 > step0+step2)
			{
				anglesArray_curr[bIdx].ANGLE = anglesArray_raw[Idx];
				anglesArray_curr[bIdx].DELTA = anglesArray_raw[Idx+1]-anglesArray_raw[Idx];
				anglesArray_curr[bIdx].activate();
				Idx+=2;
			}
			else
			{
				anglesArray_curr[bIdx].ANGLE = anglesArray_raw[Idx];
				anglesArray_curr[bIdx].DELTA = anglesArray_raw[Idx+3]-anglesArray_raw[Idx];
				anglesArray_curr[bIdx].activate();
				Idx+=4;
			}

			bIdx++;
		}
		//360° loop
		if((unsigned int)Idx==anglesArray_raw.size()-1)
		{
			step0 = anglesArray_raw[Idx+1] - anglesArray_raw[Idx];
			step1 = 360+anglesArray_raw[0] - anglesArray_raw[Idx+1];
			step2 = anglesArray_raw[1] - anglesArray_raw[0];
			
			if(step1 > step0+step2)
			{
				anglesArray_curr[bIdx].ANGLE = anglesArray_raw[Idx];
				anglesArray_curr[bIdx].DELTA = anglesArray_raw[Idx+1]-anglesArray_raw[Idx];
				anglesArray_curr[bIdx].activate();
				Idx+=2;
			}
			else
			{
				anglesArray_curr[0].ANGLE = anglesArray_raw[Idx];
				anglesArray_curr[0].DELTA = anglesArray_raw[1]-anglesArray_raw[Idx];
				anglesArray_curr[0].activate();
				Idx+=4;
			}
		bIdx++;
		}

		

		//ERROR TYP 3 : Extra small angles [CORRECTION_EPSILON]
		for(unsigned int i=0;i<anglesArray_curr.size();i++)
		{
			if(anglesArray_curr[i].DELTA<CORRECTION_EPSILON)
			{
				anglesArray_curr[i].desactivate();
			}
		}
		

	}

	//OTHER TASKS
	//	Compute dists
	for(unsigned int i=0;i<anglesArray_curr.size();i++)
	{
		if(anglesArray_curr[i].get_State())
		{
			compute_beacon_dist(anglesArray_curr[i]);
		}
		
	}


}

void MapAnalyser::detect_Side()
{
		if(anglesArray_curr[1].DIST<anglesArray_curr[2].DIST)
		{// d1 < d2
			if(config.ennemyBeacon==true)
			{
				config.side=YELLOW;
			}
			else
			{
				config.side=BLUE;
			
			}
		}
		else
		{// d1 > d2
			if(config.ennemyBeacon==true)
			{
				config.side=BLUE;
			}
			else
			{
				config.side=YELLOW;
			}
		}

}

void MapAnalyser::detect_Ennemy()
{
	if(anglesArray_raw.size()>6)
	{	
		for(int i=0;i<6;i++)
		{
			anglesArray_curr.push_back(Balise(i));	
		}
		
		config.ennemyBeacon=true;
	}
	else
	{
		for(int i=0;i<3;i++)
		{
			anglesArray_curr.push_back(Balise(i));	
		}
		config.ennemyBeacon=false;
	}
}

void MapAnalyser::auto_Mode()
{
	int nbr = count();
	if(nbr<2)
	{
		config.mode=-1;
	}
	else if(nbr==2)
	{
		config.mode=1;
	}
	else
	{
		config.mode=2;
	}
}

void MapAnalyser::refresh()
{
	if(loopOnce==false)
	{
		loopOnce=true;
		first_Scan();
	}
	else
	{
		std::vector<int> interList;
		int idx;
		
		//Copy CURR to PREV
		anglesArray_prev.clear();
		anglesArray_prev=anglesArray_curr;
		
		
		//From RAW to CURR
		raw_To_Curr(1);
		
		//Reorganise data
		if(anglesArray_curr.size()>anglesArray_prev.size())
		{ //There is more beacons than before, track beacons
			
			for(unsigned int i=0;i<anglesArray_curr.size();i++)
			{
				if(anglesArray_curr[i].get_State())
				{
					idx=track(anglesArray_curr[i]);
					
					if(idx!=-1)
					{
						anglesArray_curr[i].ID = anglesArray_prev[idx].ID;
					}
					else
					{
						interList.push_back(i);
					}
				}
			}

			for(unsigned int i=0;i<interList.size();i++)
			{
				idx = track(anglesArray_curr[interList[i]],true);
				anglesArray_curr[interList[i]].ID = anglesArray_prev[idx].ID;
			}

		}
		else if(anglesArray_curr.size()<anglesArray_prev.size())
		{ //There is less beacons than before
			//interList = anglesArray_prev;
			
			for(unsigned int i=0;i<anglesArray_curr.size();i++)
			{
				if(anglesArray_curr[i].get_State())
				{
					idx=track(anglesArray_curr[i]);
					
					if(idx!=-1)
					{
						anglesArray_curr[i].ID = anglesArray_prev[idx].ID;
						//interList.erase(interList.begin()+idx);
					}
				}
			}		
		}
		else //CURR = PREV
		{
			//same
		}
	
		//ERROR TYP 2 : Check beacons extremity masks
		
		for(unsigned int i=0;i<anglesArray_curr.size();i++)
		{
			for(unsigned int j=0;j<anglesArray_prev.size();j++)
			{
				if(anglesArray_curr[i].ID==anglesArray_prev[j].ID)
				{
					if(fabs(anglesArray_curr[i].DELTA-anglesArray_prev[j].DELTA) > MOVE_EPSILON )
					{
						anglesArray_curr[i].desactivate();
					}
				}
			}
		}


		anglesArray_raw.clear();

	}

}

int MapAnalyser::track(const Balise &b,bool mode,float eps)
{
	float min= anglesArray_prev[0].ANGLE;
	unsigned int idx=10; //random defaut values
	
	for(unsigned int i=0;i<anglesArray_prev.size();i++)
	{	
		if(anglesArray_prev[i].get_State()==(!mode))
		{
			float diff = fabs(anglesArray_prev[i].ANGLE-b.ANGLE);
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

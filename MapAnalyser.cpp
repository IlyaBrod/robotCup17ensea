#include "MapAnalyser.hpp"

MapAnalyser::MapAnalyser()
{
	beaconArray = new double[6];
	loop = 0;
	loopOnce=false;
	ennemyBeacon=false;
}


void MapAnalyser::round()
{
	if(loop==2)
	{
		loop+=1;
		loopOnce=true;
	}
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
			if(beaconArray[0]<beaconArray[1] && beaconArray[1]<beaconArray[2])
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
			if(beaconArray[2]<100)
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


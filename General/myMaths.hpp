#ifndef MYMATHS_HPP
#define MYMATHS_HPP

template<typename T> T abs(T value)
{
	if(value<0)
	{
		return -value;
	}
	else
	{
		return value;
	}
	
}

template<typename T> float pwr(T value,int n)
{
	float res=1;
	
	if(n==0)
	{
		return 1.0;
	}
	else
	{
		for(int i=0;i<n;i++)
		{
			res=res*value;
		}
		
		return res;
	}
}

template<typename T> float sqrt(T value,int n=50)
{
	T res=value/2;
	
	for(int i=0;i<n;i++)
	{
		res= 1/2 * (res+value/res);
	}
	return res;
}

#endif


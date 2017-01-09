#ifndef MATHS_HPP
#define MATHS_HPP

/**
 * Return the maximum between 2 elements
 * @param a
 * @param b
 * @return the max
 */
template<typename T> T min(T a,T b)
{
	if(a>b)
	{
		return b;
	}
	else
	{
		return a;
	}
}

/**
 * Return the minimum between 2 elements
 * @param a
 * @param b
 * @return the min
 */
template<typename T> T max(T a,T b)
{
	if(a>b)
	{
		return a;
	}
	else
	{
		return b;
	}
}

/**
 * Return absolute value of an element
 * @param value
 * @return |value|
 */
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

/**
 * Return a power of a value : value^n
 * @param value The value to evaluate
 * @param n Exposant
 * @return result
 */
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

/***
 * Return the square root of value
 * @param value
 * @param n=50 Precision of the result
 * @return result
 */
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

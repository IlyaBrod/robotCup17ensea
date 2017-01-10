#ifndef CLASS_TREENODEPATHFINDING_DEFINED
#define CLASS_TREENODEPATHFINDING_DEFINED

#include "Map.hpp"

struct TreenodePathfinding ;

struct TreenodePathfinding{
	public :
		TreenodePathfinding* father ;
		Point p ;
		double distOri ;    //distance from ori
		double distDest ;   //distance to goal

		TreenodePathfinding(const Point &p);
		TreenodePathfinding(const Point &p, const Point &dest, TreenodePathfinding* father);
		~TreenodePathfinding();

		bool operator<(const TreenodePathfinding &node);
};

//int TreenodePathfinding::nbnodes = 0 ;

#endif

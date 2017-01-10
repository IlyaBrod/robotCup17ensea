#ifndef CLASS_TREENODEPATHFINDING_DEFINED
#define CLASS_TREENODEPATHFINDING_DEFINED

#include "Map.hpp"

class TreenodePathfinding ;

class TreenodePathfinding{
	public :
		TreenodePathfinding* father ;
		Point point ;
		double distOri ;
		double distDest ;

		TreenodePathfinding(const Point &p);
		TreenodePathfinding(const Point &p, const Point &dest, TreenodePathfinding* &father);
		~TreenodePathfinding();

		bool operator<(const TreenodePathfinding* &node);
};

//int TreenodePathfinding::nbnodes = 0 ;

#endif

#ifndef CLASS_TREENODEPATHFINDING_DEFINED
#define CLASS_TREENODEPATHFINDING_DEFINED

#include "Map.hpp"

#define MAX_NODES 255

class TreenodePathfinding ;

class TreenodePathfinding{
	public :
		static int nbnodes ;

		TreenodePathfinding* father ;
		TreenodePathfinding* leftson ;
		TreenodePathfinding* rightson ;
		Point point ;
		double dist ;

		TreenodePathfinding(const Point &p);
		TreenodePathfinding(const Point &p, TreenodePathfinding* &father);
		~TreenodePathfinding();

};

//int TreenodePathfinding::nbnodes = 0 ;

#endif

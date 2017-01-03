#ifndef CLASS_TREENODEPATHFINDING_DEFINED
#define CLASS_TREENODEPATHFINDING_DEFINED

#include "Map.hpp"

#define MAX_NODES 255

class TreenodePathfinding ;

class TreenodePathfinding{
	public :
		//CALL init() before using this class
		static int nbnodes ;

		TreenodePathfinding* father ;
		TreenodePathfinding* leftson ;
		TreenodePathfinding* rightson ;
		Point point ;
		double dist ;



		static void init()const{nbnodes = 0 ;}

		TreenodePathfinding(const Point &p);
		TreenodePathfinding(const Point &p, const TreenodePathfinding* &father);
		~TreenodePathfinding();

};

#endif
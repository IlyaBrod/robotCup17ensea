#ifndef CLASS_TREENODEPATHFINDING_DEFINED
#define CLASS_TREENODEPATHFINDING_DEFINED

#include "Point.hpp"

class TreenodePathfinding ;

class TreenodePathfinding{
	private :
		TreenodePathfinding* father ;
		TreenodePathfinding* leftson ;
		TreenodePathfinding* rightson ;
		Point point ;

	public :
		TreenodePathfinding(const TreenodePathfinding* &father): father(_father), leftson(NULL), rightson(NULL), point(){}

};

#endif
#ifndef CLASS_TREENODEPATHFINDING_DEFINED
#define CLASS_TREENODEPATHFINDING_DEFINED

#include "Point.hpp"

#define MAX_NODES 255

class TreenodePathfinding ;

class TreenodePathfinding{
	private :
		//CALL init() before using this class
		static int nbnodes ;

		TreenodePathfinding* father ;
		TreenodePathfinding* leftson ;
		TreenodePathfinding* rightson ;
		Point point ;

	public :

		static void init()const{nbnodes = 0 ;}

		TreenodePathfinding(const Point &p);
		TreenodePathfinding(const Point &p, const TreenodePathfinding* &father);
		~TreenodePathfinding();

		void set_leftson(const TreenodePathfinding* &son){leftson = son ;}
		void set_rightson(const TreenodePathfinding* &son){rightson = son ;}

		void set_point(const Point &p);

};

#endif
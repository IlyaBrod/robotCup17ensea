#include "Treenode_pathfinding.hpp"

TreenodePathfinding::TreenodePathfinding(const Point &_p): p(_p), distOri(0.0), distDest(0.0){}

TreenodePathfinding::TreenodePathfinding(const Point &_p, const Point &dest, TreenodePathfinding* _father): father(_father), p(_p){
	distOri = father->distOri + sqrt((p.x-father->p.x)*(p.x-father->p.x)+(p.y-father->p.y)*(p.y-father->p.y));
	distDest = ((p.x-dest.x)*(p.x-dest.x)+(p.y-dest.y)*(p.y-dest.y));
}

TreenodePathfinding::~TreenodePathfinding(){
}

bool TreenodePathfinding::operator<(const TreenodePathfinding &node){
	return(distOri+distDest < node.distOri+node.distDest);
}

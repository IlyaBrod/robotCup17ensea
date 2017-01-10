#include "Treenode_pathfinding.hpp"

TreenodePathfinding::TreenodePathfinding(const Point &p): point(p), distOri(0.0), distDest(0.0){}

TreenodePathfinding::TreenodePathfinding(const Point &p, const Point &dest, TreenodePathfinding* &_father): father(_father), point(p){
	distOri = father->distOri + sqrt((p.X-father->p.X)*(p.X-father->p.X)+(p.Y-father->p.Y)*(p.Y-father->p.Y));
	distDest = sqrt((p.X-dest.X)*(p.X-dest.X)+(p.Y-dest.Y)*(p.Y-dest.Y));
}

TreenodePathfinding::~TreenodePathfinding(){
}

bool TreenodePathfinding::operator<(const TreenodePathfinding* &node){
	return(distOri+distDest < node->distOri+node->distDest)
}
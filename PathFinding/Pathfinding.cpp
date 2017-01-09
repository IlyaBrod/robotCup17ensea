#include "Pathfinding.hpp"

Pathfinding::Pathfinding(): nbPoint(0){}
Pathfinding::~Pathfinding(){}

void Pathfinding::buildTree(const Point& ori, const Point& dest){
	tree[0] = new TreenodePathfinding(ori, dest, NULL);
	for(int i = 0 ; i<nbRect ; i++){
		if(obstacles[i].intersect(Rectangle(ori, dest))){

		}
	}
}

TreenodePathfinding* Pathfinding::getMinTNPF(){
	TreenodePathfinding* node = tree[0] ;
	for(int i=1 ; i<nbPoint ; i++)
		if(*(tree[i])<(node))
			node = tree[i];
	return node ;
}
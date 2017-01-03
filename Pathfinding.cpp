#include "Pathfinding.hpp"

Pathfinding::Pathfinding(): root(NULL), path(NULL){}
Pathfinding::Pathfinding(const Point &origine){}
Pathfinding::~Pathfinding(){}

void Pathfinding::buildTree(const Point& ori, const Point& dest){
	for(int i = 0 ; i<nbRect ; i++){
		if(obstacles[i].intersect(Rectangle(ori, dest))){

		}
	}
}

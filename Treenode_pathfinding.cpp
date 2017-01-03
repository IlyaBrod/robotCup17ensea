#include "Treenode_pathfinding.hpp"

TreenodePathfinding::TreenodePathfinding(const Point &p): point(p), dist(0.0){}

TreenodePathfinding::TreenodePathfinding(const Point &p, TreenodePathfinding* &_father): father(_father), leftson(NULL), rightson(NULL), point(p){
	nbnodes ++ ;
}

TreenodePathfinding::~TreenodePathfinding(){
	if(leftson != NULL){
		delete leftson ;
		leftson = NULL ;
	}
	if(rightson != NULL){
		delete rightson ;
		rightson = NULL ;
	}
	nbnodes-- ;
}

void build_tree(const Point &dest){

}

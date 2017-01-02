#include "Treenode_pathfinding.hpp"

TreenodePathfinding::TreenodePathfinding(const Point &p): point(p), dist(0.0){}

TreenodePathfinding::TreenodePathfinding(const Point &pconst TreenodePathfinding* &_father): point(p), father(_father), leftson(NULL), rightson(NULL), point(){
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

void TreenodePathfinding::set_point(const Point &p){
	point = p ;
}

void build_tree(const Point &dest){
	
}
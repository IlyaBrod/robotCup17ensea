#ifndef CLASS_PATHFINDING_DEFINED
#define CLASS_PATHFINDING_DEFINED

#include "Treenode_pathfinding.hpp"

class Pathfinding{
	protected :
		Treenode_pathfinding *root ;
		Point *path ;
	public :
		Treenode_pathfinding();
		Treenode_pathfinding(const Point &origine);
		~Treenode_pathfinding();
};

#endif
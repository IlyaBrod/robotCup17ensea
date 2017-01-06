#ifndef CLASS_PATHFINDING_DEFINED
#define CLASS_PATHFINDING_DEFINED

#include "Treenode_pathfinding.hpp"
#include "Map.hpp"

class Pathfinding : public Map{
	protected :
		Treenode_pathfinding *root ;
		Point *path ;
	public :
		Treenode_pathfinding();
		Treenode_pathfinding(const Point &origine);
		~Treenode_pathfinding();

		void buildTree(const Point& ori, const Point& dest);
};

#endif
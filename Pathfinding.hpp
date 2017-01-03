#ifndef CLASS_PATHFINDING_DEFINED
#define CLASS_PATHFINDING_DEFINED

#include "Treenode_pathfinding.hpp"
#include "Map.hpp"

class Pathfinding : public Map{
	protected :
		TreenodePathfinding *root ;
		Point *path ;
	public :
		Pathfinding();
		Pathfinding(const Point &origine);
		~Pathfinding();

		void buildTree(const Point& ori, const Point& dest);
};

#endif

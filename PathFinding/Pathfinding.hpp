#ifndef CLASS_PATHFINDING_DEFINED
#define CLASS_PATHFINDING_DEFINED

#include "Treenode_pathfinding.hpp"
#include "Map.hpp"

#define MAX_POINTS 24

class Pathfinding : public Map{
	protected :
		TreenodePathfinding* tree[MAX_POINTS];
		int nbPoints;
	public :
		Pathfinding();
		~Pathfinding();

		void buildTree(const Point& ori, const Point& dest);
		TreenodePathfinding* getMinTNPF();
};

#endif

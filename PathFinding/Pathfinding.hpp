#ifndef CLASS_PATHFINDING_DEFINED
#define CLASS_PATHFINDING_DEFINED

#include "Treenode_pathfinding.hpp"

#define MAX_POINTS 256

class Pathfinding : public Map{
	protected :
		TreenodePathfinding *tree[MAX_POINTS];
		int nbPoints;
	public :
		Pathfinding();

		~Pathfinding();

		void buildTree(const Point& ori, const Point& dest);
		TreenodePathfinding* getMinTNPF();
};

#endif

#include "Pathfinding.hpp"

Pathfinding::Pathfinding(): nbPoints(0){}
Pathfinding::~Pathfinding(){
    for(int i = 0 ; i<nbPoints ; i++)
        if(tree[i]!=NULL){
            delete tree[i] ;
            tree[i] = NULL ;
        }
}

void Pathfinding::buildTree(const Point& ori, const Point& dest){
    TreenodePathfinding *node = new TreenodePathfinding(ori, dest, NULL);
	tree[0] = node ;
	nbPoints++ ;
	int obstNum = 0 ;
	double dx, dy ; //vecteur dir de la droite pos-dest
	double obsX, obsY ; //equ de droite obstacle
	double intX, intY ; //coordonnees de l'intersection
	double intD = 1000000.0 ;   //distance pos-intersection

        Point pos(node->p);
        dx = dest.x - pos.x ;
        dy = dest.y - pos.y ;
        for(int i = 0 ; i<nbRect ; i++){
            if(obstacles[i].intersect(Rectangle(ori, dest))){
                if(dx != 0){
                    if(dx > 0)
                        obsX = obstacles[i].x ;
                    else
                        obsX = obstacles[i].x + obstacles[i].w ;
                    intX = obsX ;
                    intY = pos.y+dy/dx*(obsX-pos.x);
                    if(obstacles[i].y <= intY && intY <= obstacles[i].y+obstacles[i].h){//intersection with vertical segment
                        if(dist(pos, Point(intX, intY)) < intD){
                            intD = dist(pos, Point(intX, intY));
                            obstNum = i ;
                        }
                    }
                }
                if(dy != 0){
                    if(dy > 0)
                        obsY = obstacles[i].y ;
                    else
                        obsY = obstacles[i].y + obstacles[i].h ;
                    intY = obsY ;
                    intX = pos.x+dx/dy*(obsY-pos.y);
                    if(obstacles[i].x <= intX && intX <= obstacles[i].x+obstacles[i].w){//intersection with horizontal segment
                        if(dist(pos, Point(intX, intY)) < intD){
                            intD = dist(pos, Point(intX, intY));
                            obstNum = i ;
                        }
                    }
                }
            }
        }
}

TreenodePathfinding* Pathfinding::getMinTNPF(){
	TreenodePathfinding* node = tree[0] ;
	for(int i=1 ; i<nbPoints ; i++)
		if(*(tree[i]) < *node)
			node = tree[i];
	return node ;
}

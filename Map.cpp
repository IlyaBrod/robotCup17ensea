#include "Map.hpp"

Map::Map(): obstacles(NULL), nbRect(0){}

Map::~Map(){
	delete []obstacles;
}

void Map::init(){

}

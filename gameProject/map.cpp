#include "map.h"

Element::Element(int type, int center_x, int center_y){

	
	m_type = type;
	m_center.first = center_x;
	m_center.second = center_y;
}

bool Element::isRoad(){

	switch(m_type){

		case WATER:
			return false;
		break;
		case TREE:
			return false;
		break;
		case GRASS:
			return true;
		break;
		case ROAD:
			return true;
		break;
	}

	return false;
}

bool Element::onCenter(int x, int y){

	if(m_center.first == x && m_center.second == y) return true;

	return false;
}

int Element::getCenterX(){

	return m_center.first;
}

int Element::getCenterY(){

	return m_center.second;
}

int Element::getType(){

	return m_type;
}

Map& Map::operator=(const Map &rhs){

	for(int i = 0 ; i < 1000; i++) occupy[i] = rhs.occupy[i];

	this->mapMap = rhs.mapMap;
	return *this;
}

Map::Map(const int *tiles, int width, int height){

	memset(occupy, 0, sizeof(occupy));
	mapMap.clear();
	int x = -7;
	int y = -25;
	std::cout << "\n";
	for(int i = 0 ; i < height ; i++){

		for(int j = 0 ; j < width ; j++){

			int tileIndex = i*width+j;
			std::cout << tiles[tileIndex];
			Element element(tiles[tileIndex], x+32*j, y+32*i);
			mapMap.push_back(element);
		}
		std::cout << "\n";
	}
}

int Map::getBlockIndex(int now_x, int now_y){

	//TODO find a proper algorithm
	int len = 38*25;

	for(int i = 0 ; i < len ; i++)
		if(now_x == mapMap[i].getCenterX() && now_y == mapMap[i].getCenterY()) return i;
	
	return -1;
}

void Map::setNPCPos(int x, int y){ 

	int index = getBlockIndex(x, y);
	occupy[index] = true;
}

// void Map::stickCharacter(int index, Character character){

// 	occupied[index] = character;
// }

bool Map::hasPeople(int index){

	return occupy[index];
}

// Character Map::getCharacter(int index){

// 	return occupied[index];
// }

bool Map::canWalk(int blockIndex, int dir){

	// int blockIndex = getBlockIndex(now_x, now_y);

	int ty = mapMap[blockIndex].getType();
	// std::cout << blockIndex << "\n";

	// std::cout << now_x << " " << now_y << " " << blockIndex << "\n";
	if(ty == WATER) std::cout << "Water" << "\n";
	if(ty == TREE) std::cout << "Tree" << "\n";
	if(ty == GRASS) std::cout << "GRASS" << "\n";
	if(ty == ROAD) std::cout << "ROAD" << "\n";

	switch(dir){

		case DOWN:
			if(blockIndex != -1){

				if(mapMap[blockIndex+38].isRoad() && !occupy[blockIndex+38]) return true;
				else return false;
			}
		break;
		case BACKWARD:
			if(blockIndex != -1){

				if(mapMap[blockIndex-1].isRoad() && !occupy[blockIndex-1]) return true;
				else return false;
			}
		break;
		case FORWARD:
			if(blockIndex != -1){

				std::cout << "occupy: " << blockIndex+1 << "\n";
				if(mapMap[blockIndex+1].isRoad() && !occupy[blockIndex+1]) return true;
				else return false;
			}

		break;
		case UP:
			if(blockIndex != -1){

				if(mapMap[blockIndex-38].isRoad() && !occupy[blockIndex-38]) return true;
				else return false;
			}
		break;
	}
	return true;
}

void Map::setMap(std::vector<Element> map){

	mapMap = map;
}

std::vector<Element> Map::getMap(){

	return mapMap;
}

void Map::printMap(const int *tiles){

	std::cout << "\n" << "\n";

	for(int i = 0 ; i < 25 ; i++){

		for(int j = 0 ; j < 38 ; j++){

			std::cout << mapMap[i*38+j].getCenterX() << " " << mapMap[i*38+j].getCenterY() << " " << mapMap[i*38+j].getType()  << " " <<tiles[i*38+j] << "\n";
		}
	}
}

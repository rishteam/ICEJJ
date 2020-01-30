#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "define.h"

#define GRASS 0
#define WATER 1
#define TREE 2
#define ROAD 3

class Element{

public:

	Element(int type, int center_x, int center_y);

	bool isRoad();
	bool onCenter(int x, int y);
	int getCenterX();
	int getCenterY();
	int getType();

private:

	int m_type;
	std::pair<int, int> m_center;

};

class Map{

public:

	Map() = default;
	Map(const int *tiles, int width, int height);

	bool canWalk(int blockIndex, int dir);
	int getBlockIndex(int now_x, int now_y);
	void setMap(std::vector<Element> map);
	std::vector<Element> getMap();
	void printMap(const int *tiles);
	Map &operator=(const Map &rhs);
	void setNPCPos(int x, int y);
	bool hasPeople(int index);

private:

	void map(int *tiles);
	std::vector<Element> mapMap;
	bool occupy[1000];
};
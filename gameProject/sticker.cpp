#include "sticker.h"

Sticker::Sticker(Map map){

	m_map = map;
}

void Sticker::setMap(Map map){

	m_map = map;
}

void Sticker::stickCharacter(int index, Character character){

	occupied[index] = character;
}

void Sticker::access(int index){

	occupied[index].canBattle = false;
}

Character Sticker::getCharacter(int index){

	return occupied[index];
}




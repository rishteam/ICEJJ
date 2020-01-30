#include "sticker.h"

Sticker::Sticker(Map map){

	m_map = map;
}


void Sticker::stickCharacter(int index, Character character){

	occupied[index] = character;
}


Character Sticker::getCharacter(int index){

	return occupied[index];
}




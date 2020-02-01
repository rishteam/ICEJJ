#pragma once

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "define.h"
#include "map.h"
#include "character.h"

class Sticker{

public:

	Sticker() = default;
	Sticker(Map map);

	void setMap(Map map);
	void stickCharacter(int index, Character character);
	void access(int index);
	Character getCharacter(int index);

private:

	Map m_map;
	Character occupied[1000];
};
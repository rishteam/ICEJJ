#pragma once

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "define.h"
#include "map.h"

class Character {

public:

	static const int interval = 77;

	Character();
	Character(int face);
	Character(sf::Texture texture, sf::Sprite sprite, int face);

	bool isCharacterValid();
	void collide(Character Character);

	bool talk();
	void setPosition(int x, int y);
	void setDir(int dir);
	void move();
	void update();
	void createSprite(std::string str);
	sf::Sprite show();
	void importMap(Map map);

protected:

	int checkDir();
	void animation(int animate);
	void loadImage(std::string str);
	
	sf::Sprite m_sprite;
	sf::Texture m_texture;
	sf::IntRect m_rectSourceSprite;
	sf::Clock clock;

	int m_preDir;
	int m_dir;

	bool m_collision;
	bool m_valid;

	int m_delay;

	Map m_map;
};
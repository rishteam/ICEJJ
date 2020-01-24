#pragma once

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "define.h"

class Character {

public:

	static const int interval = 77;

	Character();
	Character(sf::Texture texture, sf::Sprite sprite, int face);

	void move();
	void update();
	void createSprite(std::string str);
	sf::Sprite show();

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

};
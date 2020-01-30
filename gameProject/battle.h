#pragma once

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "define.h"
#include "character.h"

class Bar{

public:

	Bar();
	sf::RectangleShape getHpBar();
	sf::RectangleShape getEnemyHpBar();
	sf::RectangleShape getSkillBar();
	sf::RectangleShape getTextBar();
	sf::Text setTextAttr(sf::Font font, int size, sf::Color color);

	sf::Text getEnemyData();
	sf::Text getPlayerDataHp();
	sf::Text getPlayerDataExp();
	std::vector<sf::Text> getSkill();

protected:

	sf::RectangleShape hpBar;
	sf::RectangleShape enemyHpBar;
	sf::RectangleShape skillBar;
	sf::RectangleShape textBar;

	sf::Font font;
	sf::Text enemyData;
	sf::Text playerDataHp;
	sf::Text playerDataExp;
	std::vector<sf::Text> textArr;
};


class Battle : public Bar{

public:

	Battle(Character player, Character enemy);
	// void fight();
	void update();
	void draw(sf::RenderWindow window);
	void setText();

private:

	Character origin_p;
	Character origin_e;

	Character m_player;
	Character m_enemy;

	void setTool();
};
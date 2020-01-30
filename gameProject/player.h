#pragma once
#include "character.h"
#include "map.h"
#include "sticker.h"
// #include "value.h"

class  Player: public Character{


public:

	Player();

	// void collide(NPC npc);
	void updateExp(int exp);
	void learnSkill(int level);
	void processInput();
	void update();
	void keyEvent(int state);
	void move();
	void importMap(Map map);
	void stick(int x, int y, Character character);
	bool battle();
	Character getBattle();

	void setBattleSprite();
	sf::Sprite getBattleSprite();

private:

	sf::Sprite m_battleSprite;
	int m_preKey;
	int m_key;
	int m_delay;

	bool searchBattle;

	Character readyBattle;

	Sticker sticker;
	Map m_map;
	std::vector< std::pair<Skill, int> > skillCanLearn;
};
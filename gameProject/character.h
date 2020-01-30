#pragma once

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "define.h"
// #include "map.h"
#include "value.h"
#include "skill.h"
#include "skillSet.h"

class Character : public Value {

public:

	static const int interval = 77;

	Character();
	Character(int face);
	Character(sf::Texture texture, sf::Sprite sprite, int face);

	bool isCharacterValid();
	void collide(Character Character);

	void setPosition(int x, int y);
	void setDir(int dir);
	void move();
	void update();
	void createSprite(std::string str);
	sf::Sprite show();
	Skill getSkill(int index);
	int getSkillsetSize();

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


	SkillSet allSkills;
	std::vector<Skill> skillSet;
};
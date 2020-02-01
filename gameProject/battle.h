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
	sf::RectangleShape getChooseBar();
	sf::RectangleShape getDescriptionBar();
	sf::Text setTextAttr(sf::Font font, int size, sf::Color color);
	void setNarration(std::string);



	sf::Text getEnemyData();
	sf::Text getPlayerDataHp();
	sf::Text getPlayerDataExp();
	sf::Text getDescription();
	sf::Text getPlayerStatus();
	sf::Text getEnemyStatus();
	sf::Text getNarration();
	std::vector<sf::Text> getSkill();

protected:

	sf::RectangleShape hpBar;
	sf::RectangleShape enemyHpBar;
	sf::RectangleShape skillBar;
	sf::RectangleShape textBar;
	sf::RectangleShape descriptionBar;


	sf::RectangleShape choose;

	sf::Font font;
	sf::Text enemyData;
	sf::Text playerDataHp;
	sf::Text playerDataExp;
	sf::Text description;
	sf::Text playerStatus;
	sf::Text enemyStatus;
	sf::Text narration;
	std::vector<sf::Text> textArr;
};


class Battle : public Bar{

public:

#define HEALTH 0
#define ATTACK 1
#define DEFEND 2
#define SPEED 3

#define None 0
#define Poison 1
#define Burn 2
#define Addatk 3
#define Adddef 4
#define Addspd 6
#define Heal 7

#define POS_0_0 810, 655, 0
#define POS_1_0 810, 705, 1
#define POS_2_0 810, 755, 2
#define POS_0_1 1010, 655, 3
#define POS_1_1 1010, 705, 4
#define POS_2_1 1010, 755, 5

#define POS0_0 0
#define POS1_0 1
#define POS2_0 2
#define POS0_1 3
#define POS1_1 4
#define POS2_1 5

	Battle(Character player, Character enemy);
	struct FightController{

		int damaged = 0;
		int buffAtk = 0;
		int buffDef = 0;
		int buffSpd = 0;
		int debAtk  = 0;
		int debDef  = 0;
		int debSpd  = 0;

		int effectType = None;
		int buffType  = None;
		int index;

		int burnValue = 18;
		int poisonValue = 10;

		bool miss = false;

		void clearDamage(){

			damaged = 0;
		}

		void init(){
		
			damaged = 0;//need to delete this line
			buffAtk = 0;
			buffDef = 0;
			buffSpd = 0;
			debAtk = 0;
			debDef = 0;
			debSpd = 0;
			index = 0;
			miss = false;
		}


	}playerFightController, enemyFightController;
	// void fight();
	bool update();
	void draw(sf::RenderWindow window);
	void setText();
	void processInput();
	void keyEvent(int State);
	void changeChooseBarPos(int x, int y, int pos);
	void attack();//change to return struct
	bool finish();
	bool playerWin();
	sf::Sprite getPlayerSprite();
	sf::Sprite getEnemySprite();

	int hotfixfight();
	int hotfixEffect();
	// bool upd();
	Character effect(Character first, Character second, int who);
	std::string setDescriptionLine();

	//hotfix
	bool toExe = false;
	bool toFin = false;

	bool hotFixLeave = false;
	bool atkOnce = false;
	bool enemyAtkOnce = false;
	bool battleFinish = false;
	bool hotfixLeave2 = false;
	bool flag = false;
	bool flag2 = false;

private:

	Character origin_p;
	Character origin_e;

	Character m_player;
	Character m_enemy;

	void setTool();

	int m_key;
	int m_prekey = CONFIRM;

	int nowPos;

	//hotfix;
	bool keyFlag = true;
	bool fightingFlag = false;
	int s = -1;
	int t = -1;

};
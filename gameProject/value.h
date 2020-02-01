#pragma once

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "define.h"

class Value{

public:

#define HEALTH 0
#define ATTACK 1
#define DEFEND 2
#define SPEED  3

#define None 0
#define Poison 1
#define Burn 2
#define Addatk 3
#define Adddef 4
#define Addspd 6
#define Heal 7

	Value();

	int getLevel();
	int getHp();
	int getDef();
	int getExp();
	int getAtk();
	int getSpd();
	int getPosStatus();
	int getNegStatus();

	int getNextLevelExp();
	
	void levelUp();
	void updateExp(int exp);
	int updateNextLevelExp();
	void addKillType(int type);
	void setAbilities(int LEVEL = 5, int HP = 24, int ATK = 12, int DEF = 5, int SPD = 8);

// protected:
	int getPropotion(int num);

	int m_LEVEL;
	int m_HP;
	int m_EXP;
	int m_ATK;
	int m_DEF;
	int m_SPD;
	int m_posStatus;
	int m_negStatus;

	int nextLevelExp;

	int killTypeCounter[4];
};
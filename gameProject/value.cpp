#include "value.h"

Value::Value(){

	for(int i = 0 ; i < 4 ; i++) killTypeCounter[i] = 0;

	m_LEVEL = 5;
	m_HP = 24;
	m_EXP = 0;
	m_ATK = 12;
	m_DEF = 5;
	m_SPD = 8;
	m_posStatus = None;
	m_negStatus = None;
	nextLevelExp = updateNextLevelExp();
}

void Value::addKillType(int type){

	if(std::accumulate(killTypeCounter, killTypeCounter+4, 0) == 50) return;

	switch (type){

		case HEALTH:
			killTypeCounter[HEALTH]++;
		break;
		case ATTACK:
			killTypeCounter[ATTACK]++;
		break;
		case DEFEND:
			killTypeCounter[DEFEND]++;
		break;
		case SPEED:
			killTypeCounter[SPEED]++;
		break;
	}
}

int Value::updateNextLevelExp(){

	int tmp = (m_LEVEL-5 <= 0 ? 0 : m_LEVEL-10);

	return m_LEVEL * m_LEVEL + 7*tmp; 
}

int Value::getPropotion(int num){

	if(num <= 3) return 0;
	else if(3 < num <= 10) return 1;
	else if(10 < num <= 35) return 2;
	else if(35 < num <= 48) return 3;
	else if(48 < num <= 50) return 4;
}

void Value::updateExp(int exp){

	while(exp--){

		m_EXP++;
		if(m_EXP == nextLevelExp){

			levelUp();
			m_EXP = 0;
			nextLevelExp = updateNextLevelExp();
		}
	}
}

void Value::levelUp(){

	m_LEVEL += 1;
	m_HP += 2 + getPropotion(killTypeCounter[HEALTH]);
	m_ATK += 1 + getPropotion(killTypeCounter[ATTACK]);
	m_DEF += 1 + getPropotion(killTypeCounter[DEFEND]);
	m_SPD += 1 + getPropotion(killTypeCounter[SPEED]);
	m_negStatus = None;
}

int Value::getLevel(){

	return m_LEVEL;
}

int Value::getHp(){

	return m_HP;
}

int Value::getExp(){

	return m_EXP;
}

int Value::getAtk(){

	return m_ATK;
}

int Value::getSpd(){

	return m_SPD;
}

int Value::getPosStatus(){

	return m_posStatus;
}

int Value::getNegStatus(){

	return m_negStatus;
}

int Value::getNextLevelExp(){

	return nextLevelExp;
}

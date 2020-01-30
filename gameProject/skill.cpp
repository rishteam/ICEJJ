#include "skill.h"

Skill::Skill(std::string name , int power, int rate, std::string description, int id, int additional){

	m_name = name;
	m_power = power;
	m_rate = rate;
	m_description = description;
	m_additional = additional;
	m_id = id;
}

bool Skill::hit(){

	std::random_device rd;
	std::default_random_engine gen = std::default_random_engine(rd());
	std::uniform_int_distribution<int> dis(1, 100);

	if(dis(gen) <= m_rate) return true;
	else false;
}

std::string Skill::getName(){

	return m_name;
}

int Skill::getId(){

	return m_id;
}

int Skill::getDamage(int atk, int def){

	int ret = atk*(m_power/100) - def;

	return (def <= 0 ? 1 : ret);
}
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

	int rand = dis(gen);
	std::cout << "rand: " << rand << " rate: " << m_rate << "\n";
	if(rand <= m_rate){

		std::cout << "hit\n";
		return true;
	}
	else return false;
}

std::string Skill::getName(){

	return m_name;
}

std::string Skill::getDescription(){

	return m_description;
}

int Skill::getId(){

	return m_id;
}

int Skill::getPower(){

	return m_power;
}

int Skill::getRate(){

	return m_rate;
}

int Skill::getAdditional(){

	return m_additional;
}

int Skill::getDamage(int atk, int def){

	std::cout << "power: " << m_power << std::endl; 
	std::cout << "atk: " << atk << std::endl;
	std::cout << "def: " << def << std::endl;
	double tmp = m_power;
	int ret = atk*(tmp/100) - def/3;
	if(m_power != 0) return (ret<= 0 ? 1 : ret);
	else return 0;
}
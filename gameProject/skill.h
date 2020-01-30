#pragma once

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "define.h"
#include <random>

class Skill{

public:
#define None 0
#define Poison 1
#define Burn 2
#define Addatk 3
#define Adddef 4
#define Addspd 6
#define Heal 6

	Skill(std::string name, int power, int rate, std::string description, int id, int additional);

	bool hit();
	int getDamage(int atk, int def);

	int getId();
	std::string getName();

private:

	std::string m_name;
	int m_id;
	int m_power;
	int m_rate;
	int m_additional;
	std::string m_description;
};
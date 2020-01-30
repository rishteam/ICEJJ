#pragma once

#include "skill.h"

class SkillSet{

public:
#define None 0
#define Poison 1
#define Burn 2
#define Addatk 3
#define Adddef 4
#define Addspd 6
#define Heal 6

	SkillSet();
	Skill findSkillById(int id);

private:
	std::vector<Skill> skillset;

};
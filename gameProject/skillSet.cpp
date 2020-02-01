#include "skillSet.h"

SkillSet::SkillSet(){


	Skill slash("Slash", 50, 100, "Attack other once\n", 0, None);
	skillset.push_back(slash);

	Skill holdSheild("Hold Sheild", 0, 100, "Improve yourself's DEF\n", 1, Adddef);
	skillset.push_back(holdSheild);

	Skill swordDance("Sword Dance", 0, 100, "Improve yourself's ATK\n", 2, Addatk);
	skillset.push_back(swordDance);

	Skill agility("Agility", 0, 100, "Improve yourself's SPD", 3, Addspd);
	skillset.push_back(agility);

	Skill meditation("Meditation", 0, 100, "Improve yourself's DEF\n", 4, Adddef);
	skillset.push_back(meditation);

	Skill doubleSword("Starbust", 120, 45, "STARBUST STREAM", 5, None);
	skillset.push_back(doubleSword);

	Skill lifeCircle("Life Circle", 0, 100, "Recover every round", 6, Heal);
	skillset.push_back(lifeCircle);

	Skill ghostFire("Ghost Fire", 0, 70, "Burn, Damage other every round", 7, Burn);
	skillset.push_back(ghostFire);

	Skill toxic("Toxic", 0, 55, "Poison, Damage other every\nround", 8, Poison);
	skillset.push_back(toxic);

	Skill godsRule("God's Rule", 0, 10, "Force other Hp set to 1", 9, None);
	skillset.push_back(godsRule);

	Skill thorKill("Thor Kill", 90, 100, "Powerfuk ATK", 10, None);
	skillset.push_back(thorKill);
}

Skill SkillSet::findSkillById(int id){

	for(int i = 0 ; i < skillset.size() ; i++){

		if(skillset[i].getId() == id) return skillset[i];
	}

	return Skill("bug", 200, 100, "??????", -1, Poison);
}
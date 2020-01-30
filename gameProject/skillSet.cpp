#include "skillSet.h"

SkillSet::SkillSet(){


	Skill slash("Slash", 50, 100, "attack once", 0, None);
	skillset.push_back(slash);

	Skill holdSheild("Hold Sheild", 0, 100, "defense improve", 1, Adddef);
	skillset.push_back(holdSheild);

	Skill swordDance("Sword Dance", 0, 100, "attack improve", 2, Addatk);
	skillset.push_back(swordDance);

	Skill agility("Agility", 0, 100, "speed improve", 3, Addspd);
	skillset.push_back(agility);

	Skill meditation("Meditation", 0, 100, "defense improve", 4, Adddef);
	skillset.push_back(meditation);

	Skill doubleSword("Starbust", 80, 95, "starbu...", 5, None);
	skillset.push_back(doubleSword);

	Skill lifeCircle("Life Circle", 0, 100, "recover every round", 6, Heal);
	skillset.push_back(lifeCircle);

	Skill ghostFire("Ghost Fire", 0, 50, "in burn, you will be damaged every round", 7, Burn);
	skillset.push_back(ghostFire);

	Skill toxic("Toxic", 0, 75, "in poison, you will be damaged every round", 8, Poison);
	skillset.push_back(toxic);

	Skill godsRule("God's Rule", 0, 10, "hp set to 1", 9, None);
	skillset.push_back(godsRule);

	Skill thorKill("Thor Kill", 90, 100, "powerfull", 10, None);
}

Skill SkillSet::findSkillById(int id){

	for(int i = 0 ; i < 10 ; i++){

		if(skillset[i].getId() == id) return skillset[i];
	}

	return Skill("bug招", 200, 100, "??????", -1, Poison);
}
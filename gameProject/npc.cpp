#include "npc.h"

NPC::NPC(){

	std::cout << "npc one" << "\n";
	m_movementLen = 0;
	m_movementIndex = 0;
	counter = 1;
	delayTime = 50;

	provideExp = m_LEVEL*m_LEVEL + std::max(std::max(m_ATK, m_DEF), m_SPD);
}

NPC::NPC(int face){

	std::cout << "npc two" << "\n";

	int left = 0;

	if(face == BACKWARD || face == FORWARD) left = 539;

	face -= 1;
	int y_pos = face * 77;

	m_rectSourceSprite = sf::IntRect(left, y_pos, 77, 77);
	std::cout << "Character two" << "\n";
	m_preDir = face+1;
	m_dir = STOP;

	m_valid = true;
	m_collision = false;
	m_movementLen = 0;
	m_movementIndex = 0;
	counter = 1;
	delayTime = 50;
}

NPC::NPC(float time){

	m_movementLen = 0;
	m_movementIndex = 0;
	counter = 1;
	delayTime = time;
}

void NPC::setSkill(int type){

	std::cout << "set Npc Skill\n";
	skillSet.push_back(allSkills.findSkillById(0));

	switch(type){

		case ENEMYHEA:
			skillSet.push_back(allSkills.findSkillById(1));
			skillSet.push_back(allSkills.findSkillById(2));
			skillSet.push_back(allSkills.findSkillById(6));
			skillSet.push_back(allSkills.findSkillById(7));
		break;
		case ENEMYATK:
			skillSet.push_back(allSkills.findSkillById(2));
			skillSet.push_back(allSkills.findSkillById(6));
			skillSet.push_back(allSkills.findSkillById(10));
			break;
		case ENEMYDEF:
			skillSet.push_back(allSkills.findSkillById(1));
			skillSet.push_back(allSkills.findSkillById(4));
			skillSet.push_back(allSkills.findSkillById(6));
		break;
		case ENEMYSPD:
			skillSet.push_back(allSkills.findSkillById(3));
		break;
		case Boss:
			skillSet.push_back(allSkills.findSkillById(9));
			skillSet.push_back(allSkills.findSkillById(10));
			skillSet.push_back(allSkills.findSkillById(8));
			skillSet.push_back(allSkills.findSkillById(4));
			skillSet.push_back(allSkills.findSkillById(6));
			break;
	}
}

void NPC::setDelay(float time){

	delayTime = time;
}

void NPC::delay(){

	counter++;
	if(counter == delayTime) counter = 0;
}

void NPC::checkMovementValid(int loop[], int len){

	int checkUpDown = 0;
	int checkForwardAndBackward = 0;

	for(int i = 0 ; i < len ; i++){

		if(loop[i] == UP || loop[i] == DOWN){

			if(loop[i] == UP) checkUpDown++;
			else checkUpDown --;
		}
		else if(loop[i] == FORWARD || loop[i] == BACKWARD){

			if(loop[i] == FORWARD) checkForwardAndBackward++;
			else checkForwardAndBackward --;
		}
	}

	if(checkUpDown) printf("Invalid movment, too much up or down\n");
	if(checkForwardAndBackward) printf("Invalid movment, too much forward or backward\n");

	m_valid = false;
}

void NPC::setNPCMovement(int loop[], int len){

	checkMovementValid(loop, len);

	m_movementLen = len;

	m_movement.insert(m_movement.begin(), loop, loop+m_movementLen);
}

void NPC::processInput(){

	int dir = m_movement[m_movementIndex];
	// printf("%d\n", m_movement[m_movementIndex]);
	// std::cout << dir << "\n";


	switch(dir){

		case UP:
			setDir(UP);
			break;
		case DOWN:
			setDir(DOWN);
			break;
		case BACKWARD:
			setDir(BACKWARD);
			break;
		case FORWARD:
			setDir(FORWARD);
			break;
		case CONFIRM:
			setDir(STOP);
			//TODO
			break;
		case ESCAPE:
			setDir(STOP);
			//TODO
			break;
		case STOP:
			setDir(STOP);
			break;
	}
}
void NPC::createSprite(int type){

	m_type = type;
	std::string str;
	if(type == ENEMYHEA) str = "health.png";
	if(type == ENEMYATK) str = "attack.png";
	if(type == ENEMYDEF) str = "defense.png";
	if(type == ENEMYSPD) str = "speed.png";
	if(type == Boss)     str = "boss.png";

	std::string tmp = "data/picture/character/" + str;

	loadImage(tmp);
	m_sprite.setTexture(m_texture);
	m_sprite.setTextureRect(m_rectSourceSprite);
	m_sprite.setScale(0.6f, 0.6f);
	setSkill(type);
}

void NPC::update(){

	if(m_dir != STOP) m_preDir = m_dir;
	// std::cout << "npc: " << m_preDir << "\n";
	m_sprite.setTextureRect(m_rectSourceSprite);

	delay();
	if(!counter) m_movementIndex++;
	if(m_movementIndex == m_movementLen) m_movementIndex = 0;
}

void NPC::setBattleSprite(){

	m_battleSprite.setTexture(m_texture);
	m_battleSprite.setTextureRect(sf::IntRect(0, 0, 77, 77));
	m_battleSprite.setScale(1.2f, 1.2f);
	m_battleSprite.setPosition(700, 60);
}
#include "battle.h"

Bar::Bar(){

	hpBar.setSize(sf::Vector2f(400,68));
	enemyHpBar.setSize(sf::Vector2f(400, 100));
	skillBar.setSize(sf::Vector2f(500, 150));
	textBar.setSize(sf::Vector2f(798, 80));

	hpBar.setOutlineColor(sf::Color::Black);
	hpBar.setOutlineThickness(2);
	hpBar.setPosition(900, 580);

	textBar.setOutlineColor(sf::Color::Black);
	textBar.setOutlineThickness(1);
	textBar.setPosition(0, 720);

	skillBar.setOutlineColor(sf::Color::Black);
	skillBar.setOutlineThickness(2);
	skillBar.setPosition(800, 650);
	skillBar.setFillColor(sf::Color(0, 0, 0, 128));

	enemyHpBar.setOutlineColor(sf::Color::Red);
	enemyHpBar.setOutlineThickness(3);
	enemyHpBar.setPosition(0, 0);


	choose.setSize(sf::Vector2f(180, 40));
	choose.setFillColor(sf::Color(77, 255, 255, 204));
	choose.setPosition(810, 655);

	descriptionBar.setSize(sf::Vector2f(240, 150));
	descriptionBar.setOutlineThickness(1);
	descriptionBar.setOutlineColor(sf::Color::Black);
	descriptionBar.setFillColor(sf::Color(77, 255, 255));
	descriptionBar.setPosition(558, 650);

	if (!font.loadFromFile("data/font/arial.ttf"))
	{
	}

	for(int i = 0 ; i < 6 ; i++){

		sf::Text tmp;

		if(i < 3) tmp.setPosition(820, i*50 + 660);
		else tmp.setPosition(1020, (i-3)*50 + 660);

		tmp.setFont(font);
		tmp.setFillColor(sf::Color::Black);
		tmp.setCharacterSize(24);
		tmp.setString("");
		textArr.push_back(tmp);
	}
	// enemyData = setTextAttr(font, 44, sf::Color::Black);
	// playerDataHp = setTextAttr(font, 26, sf::Color::Black);
	// playerDataExp = setTextAttr(font, 24, sf::Color::Black);

	enemyData.setFont(font);
	enemyData.setFillColor(sf::Color::Black);
	enemyData.setCharacterSize(44);
	enemyData.setPosition(220, 40);

	playerDataHp.setFont(font);
	playerDataHp.setFillColor(sf::Color::Black);
	playerDataHp.setCharacterSize(44);
	playerDataHp.setPosition(1020, 600);

	playerDataExp.setFont(font);
	playerDataExp.setFillColor(sf::Color::Blue);
	playerDataExp.setCharacterSize(38);
	playerDataExp.setPosition(1090, 530);

	description.setFont(font);
	description.setFillColor(sf::Color::Black);
	description.setCharacterSize(16);
	description.setPosition(560, 660);

	playerStatus.setFont(font);
	playerStatus.setCharacterSize(20);
	playerStatus.setPosition(930, 620);
	
	enemyStatus.setFont(font);
	enemyStatus.setCharacterSize(20);
	enemyStatus.setPosition(50, 60);

	narration.setFont(font);
	narration.setCharacterSize(16);
	narration.setPosition(10, 725);
	narration.setFillColor(sf::Color::Black);
	narration.setString("choose skill\n");
}

void Bar::setNarration(std::string str){

	narration.setString(str);
}

sf::RectangleShape Bar::getChooseBar(){

	return choose;
}

sf::RectangleShape Bar::getDescriptionBar(){

	return descriptionBar;
}

sf::Text Bar::getDescription(){

	return description;
}

sf::Text Bar::getNarration(){

	return narration;
}

sf::Text Bar::setTextAttr(sf::Font font, int size, sf::Color color){

	sf::Text tmp;
	tmp.setFont(font);
	tmp.setCharacterSize(size);
	tmp.setFillColor(color);
	return tmp;
}

std::vector<sf::Text> Bar::getSkill(){

	return textArr;
}

sf::Text Bar::getPlayerStatus(){

	return playerStatus;
}

sf::Text Bar::getEnemyStatus(){

	return enemyStatus;
}

sf::Text Bar::getEnemyData(){

	return enemyData;
}

sf::Text Bar::getPlayerDataExp(){

	return playerDataExp;
}

sf::Text Bar::getPlayerDataHp(){

	return playerDataHp;
}

sf::RectangleShape Bar::getHpBar(){

	return hpBar;
}

sf::RectangleShape Bar::getEnemyHpBar(){

	return enemyHpBar;
}

sf::RectangleShape Bar::getSkillBar(){

	return skillBar;
}

sf::RectangleShape Bar::getTextBar(){

	return textBar;
}

Battle::Battle(Character player, Character enemy){

	std::cout << "battle: " << enemy.getSkillsetSize() << "\n";
	origin_p = m_player = player;
	origin_e = m_enemy = enemy;


	nowPos = 0;
}

std::string Battle::setDescriptionLine(){

	std::string power = "POWER: " + std::to_string(origin_p.getSkill(nowPos).getPower()) + "\n";
	std::string rate  = "HITRATE: " + std::to_string(origin_p.getSkill(nowPos).getRate()) + "\n\n";
	std::string des   = origin_p.getSkill(nowPos).getDescription();

	return power + rate + des;
}

sf::Sprite Battle::getEnemySprite(){

	return origin_e.getBattleSprite();
}

sf::Sprite Battle::getPlayerSprite(){

	return origin_p.getBattleSprite();
}


void Battle::setText(){

	// enemyData.setString("FFFF");
	enemyData.setString(std::to_string(m_enemy.getHp()) + " / " + std::to_string(origin_e.getHp()));
	playerDataHp.setString(std::to_string(m_player.getHp()) + " / " + std::to_string(origin_p.getHp()));
	playerDataExp.setString( std::to_string(m_player.getExp()) + " / " + std::to_string(origin_p.getExp()));
	
	for(int i = 0 ; i < origin_p.getSkillsetSize(); i++) textArr[i].setString(origin_p.getSkill(i).getName());


	description.setString(setDescriptionLine());

	if(m_player.getNegStatus() == Burn){

		playerStatus.setFillColor(sf::Color::Red);
		playerStatus.setString("Burn");
	}
	else if(m_player.getNegStatus() == Poison){

		playerStatus.setFillColor(sf::Color(153, 0, 204));
		playerStatus.setString("Poison");
	}
	else playerStatus.setString("");
	
	if(m_enemy.getNegStatus() == Burn){

		enemyStatus.setFillColor(sf::Color::Red);
		enemyStatus.setString("Burn");
	}
	else if(m_enemy.getNegStatus() == Poison){

		enemyStatus.setFillColor(sf::Color(153, 0, 204));
		enemyStatus.setString("Poison");
	}
	else enemyStatus.setString("");

}

void Battle::changeChooseBarPos(int x, int y, int pos){

	// std::cout << pos << "\n";
	choose.setPosition(x, y);
	nowPos = pos;
}

void Battle::processInput(){

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		m_key = UP;

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		m_key = DOWN;

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		m_key = BACKWARD;

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		m_key = FORWARD;

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
		m_key = CONFIRM;

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		m_key = ESCAPE;

	else
		m_key = STOP;
}

void Battle::keyEvent(int State){

	int state = State;
	// narration.setString("choose skill\n");
	// std::cout << state << "\n";

	if(m_key != STOP){

		if(!keyFlag){

			keyFlag = true;
			std::cout << "in" << "\n";
			switch(m_key){

				case UP:
					std::cout << "Up" << "\n";
					if(nowPos == POS0_0 || nowPos == POS0_1) break;
					else{

						if(nowPos - 1 >= origin_p.getSkillsetSize()) break;
						else if(nowPos == POS1_0) changeChooseBarPos(POS_0_0);
						else if(nowPos == POS1_1) changeChooseBarPos(POS_0_1);
						else if(nowPos == POS2_0) changeChooseBarPos(POS_1_0);
						else if(nowPos == POS2_1) changeChooseBarPos(POS_1_1);
					} 
				break;
				case DOWN:
					std::cout << "Down" << "\n";
					if(nowPos == POS2_0 || nowPos == POS2_1) break;
					else{

						if(nowPos + 1 >= origin_p.getSkillsetSize()) break;
						else if(nowPos == POS0_0) changeChooseBarPos(POS_1_0);
						else if(nowPos == POS0_1) changeChooseBarPos(POS_1_1);
						else if(nowPos == POS1_0) changeChooseBarPos(POS_2_0);
						else if(nowPos == POS1_1) changeChooseBarPos(POS_2_1);
					}
				break;
				case BACKWARD:
					std::cout << "BACKWARD" << "\n";
					if(nowPos == POS0_0 || nowPos == POS1_0 || nowPos == POS2_0) break;
					else{

						if(nowPos - 3 >= origin_p.getSkillsetSize()) break;
						else if(nowPos == POS0_1) changeChooseBarPos(POS_0_0);
						else if(nowPos == POS1_1) changeChooseBarPos(POS_1_0);
						else if(nowPos == POS2_1) changeChooseBarPos(POS_2_0);
					}
				break;
				case FORWARD:
					std::cout << "FORWARD" << "\n";
					if(nowPos == POS0_1 || nowPos == POS1_1 || nowPos == POS2_1) break;
					else{

						if(nowPos + 3 >= origin_p.getSkillsetSize()) break;
						else if(nowPos == POS0_0) changeChooseBarPos(POS_0_1);
						else if(nowPos == POS1_0) changeChooseBarPos(POS_1_1);
						else if(nowPos == POS2_0) changeChooseBarPos(POS_2_1);
					}
				break;
				case CONFIRM:
					std::cout << "press Z\n";
					switch(state){

						case STRATEGY:
							std::cout << "STRATEGY" << std::endl;
							playerFightController.init();
							enemyFightController.init();
							attack();
							toExe = true;
							s = 0;
							t = 0;
							flag = false;
							flag2 = false;
							atkOnce = false;
						break;

						case EXECUTE:
							// if(s == -1) s = 0;
							if(s == 0) s = 1;
							else if(s == 1) s = 2;
						break;
						
						case EFFECT:
							std::cout << "Press effect\n";
							if(t == 0) t = 1;
							else if(t == 1) t = 2; 
						break;

						case FINISH:
						break;
					}
				break;
				case STOP:
				break;
			}
		}
	}
	else {

		keyFlag = false;
	}

	// std::cout << nowPos << "\n";
	m_prekey = m_key;
}

void Battle::attack(){

	int size = m_enemy.getSkillsetSize();

	std::random_device rd;
	std::default_random_engine gen = std::default_random_engine(rd());
	std::uniform_int_distribution<int> dis(1, size);

	int enemySkillIndex = dis(gen) - 1;
	std::cout << "enemy skill " << enemySkillIndex << "\n";

	if(m_enemy.getSkill(enemySkillIndex).hit()){

		enemyFightController.damaged = m_enemy.getSkill(enemySkillIndex).getDamage(m_enemy.getAtk(), m_player.getDef());
		// std::cout << "111: " << enemyFightController.damaged << "\n";
		enemyFightController.index = enemySkillIndex;
		// std::cout << enemyFightController.damaged << "\n";
		switch (m_enemy.getSkill(enemySkillIndex).getAdditional()){

			case None:
				std::cout << "None" << "\n";
			break;
			case Poison:
				// enemyFightController.effectType = Poison;
			break;
			case Burn:
				// enemyFightController.effectType = Burn;
			break;
			case Addatk:
				enemyFightController.buffAtk = m_enemy.getLevel()/2;
			break;
			case Adddef:
				enemyFightController.buffDef = m_enemy.getLevel()/2;
			break;
			case Addspd:
				std::cout << "Addspd" << "\n";
				enemyFightController.buffSpd = m_enemy.getLevel()/2;
			break;
			case Heal:
				std::cout << "Heal" << "\n";
				// enemyFightController.buffType = Heal;
			break;
		}
	}
	else enemyFightController.miss = true;

	if(m_player.getSkill(nowPos).hit()){

		playerFightController.damaged = m_player.getSkill(nowPos).getDamage(m_player.getAtk(), m_enemy.getDef());
		// std::cout << "222: " << playerFightController.damaged << std::endl;
		switch(m_player.getSkill(nowPos).getAdditional()){

			case None:
			break;
			case Poison:
				// playerFightController.effectType = Poison;
			break;
			case Burn:
				// playerFightController.effectType = Burn;
			break;
			case Addatk:
				playerFightController.buffAtk = m_enemy.getLevel()/2;
			break;
			case Adddef:
				playerFightController.buffDef = m_enemy.getLevel()/2;
			break;
			case Addspd:
				playerFightController.buffSpd = m_enemy.getLevel()/2;
			break;
			case Heal:
				// playerFightController.buffType = Heal;
			break;
			}
	}
	else playerFightController.miss = true;
	
}

bool Battle::update(){


	if(m_player.getSpd() >= m_enemy.getSpd()){

		m_enemy = effect(m_player, m_enemy, 0);

		if(playerFightController.damaged == 0){


			m_player = effect(m_enemy, m_player, 1);
		}
		// std::cout << playerFightController.damaged << "\n";
	}
	else {

		m_player = effect(m_enemy, m_player, 1);

		if(enemyFightController.damaged == 0)
			m_enemy = effect(m_player, m_enemy, 0);
	}

	if(playerFightController.damaged == 0 && enemyFightController.damaged == 0)
		return true;

	return false;
}

int Battle:: hotfixfight(){

	// std::cout << s << "\n";
	if (m_enemy.m_HP == 0 || m_player.m_HP == 0) battleFinish = true; 
	if(m_player.getSpd() >= m_enemy.getSpd()){

		if(s==0){

			if(!atkOnce){
				
				std::cout << "your turn\n";
				std::string str;
				str += "you use " + m_player.getSkill(nowPos).getName() + "!\n";

				if(playerFightController.miss) str += "Miss!";
				
				else{

					// narration.setString("you use " + m_player.getSkill(nowPos).getName() + "!");

					std::cout << "aaaass: " << m_player.getSkill(nowPos).getId() << "\n";
					if (m_player.getSkill(nowPos).getId() == 2){

						if(playerFightController.buffAtk) m_player.m_ATK += playerFightController.buffAtk;
						str += "your ATK improve!";
					}
					if (m_player.getSkill(nowPos).getId() == 3){

						if(playerFightController.buffSpd) m_player.m_SPD += playerFightController.buffSpd;
						str += "your SPD improve!";
					}
					if(m_player.getSkill(nowPos).getId() == 7 && playerFightController.effectType != 0){

						str += "failed\n";
					}
					else if(m_player.getSkill(nowPos).getId() == 7){

						std::cout << "burn\n";
						playerFightController.effectType = Burn;
						playerFightController.debAtk = m_enemy.getAtk()/2;
						m_enemy.m_negStatus = Burn;
						str += "enemy get burn!\n";
					}


					m_enemy.m_HP -= playerFightController.damaged;
					if(m_enemy.m_HP <= 0) m_enemy.m_HP = 0;
				}
				narration.setString(str);
				atkOnce = true;
				if(m_enemy.m_HP == 0) hotFixLeave = true;
			}

		}
		else if(s == 1){

			if(!enemyAtkOnce){

				std::cout << "enemy's turn\n";
				// std::cout << enemyFightController.buffType << "\n";
				std::string str;
				str += "enemy use " + m_enemy.getSkill(enemyFightController.index).getName() + "!\n";

				if(enemyFightController.miss) str += "Miss!";
				else {

					if(m_enemy.getSkill(enemyFightController.index).getId() == 1){

						if(enemyFightController.buffDef) m_enemy.m_DEF += enemyFightController.buffDef;
						str += "enemy's DEF improve!";
					}
					if(m_enemy.getSkill(enemyFightController.index).getId() == 2){

						if(enemyFightController.buffAtk) m_enemy.m_ATK += enemyFightController.buffAtk;
						str += "enemy's ATK improve!";
					}
					if(m_enemy.getSkill(enemyFightController.index).getId() == 3){

						if(enemyFightController.buffSpd) m_enemy.m_SPD += enemyFightController.buffSpd;
						str += "enemy's SPD improve!";
					}
					if(m_enemy.getSkill(enemyFightController.index).getId() == 4){

						if(enemyFightController.buffDef) m_enemy.m_DEF += enemyFightController.buffDef;
						str += "enemy's DEF improve!";
					}
					if(m_enemy.getSkill(enemyFightController.index).getId() == 6 && enemyFightController.buffType != 0) str += "failed";
					else if(m_enemy.getSkill(enemyFightController.index).getId() == 6){

						enemyFightController.buffType = Heal;
						str += "enemy's will recover every round!";
					}
					if(m_enemy.getSkill(enemyFightController.index).getId() == 7 && enemyFightController.effectType != 0) str += "failed";
					else if(m_enemy.getSkill(enemyFightController.index).getId() == 7){

						enemyFightController.effectType = Burn;
						enemyFightController.debAtk = m_player.getAtk()/2;
						m_player.m_negStatus = Burn;
						str += "you got burn!";
					}
					if(m_enemy.getSkill(enemyFightController.index).getId() == 8 && enemyFightController.effectType != 0) str += "failed";
					else if(m_enemy.getSkill(enemyFightController.index).getId() == 8){

						enemyFightController.effectType = Poison;
						m_player.m_negStatus = Poison;
						str += "you got poison!";
					}
					if(m_enemy.getSkill(enemyFightController.index).getId() == 9){
						
						m_player.m_HP = 1;
						str += "your hp set to 1!\n";
					}
					else{

						m_player.m_HP -= enemyFightController.damaged;
					}

					if(m_player.m_HP <= 0) m_player.m_HP = 0;

				}
				narration.setString(str);
				enemyAtkOnce = true;
				// hotFixLeave = true;
			}

		}
		else if(s == 2){

			// std::cout << "s=2\n";
			hotFixLeave = true;
		}
	}
	// std::cout << m_enemy.getHp() << std::endl;
	if(m_enemy.m_HP < 0) m_enemy.m_HP = 0;
	if(m_player.m_HP < 0) m_player.m_HP = 0;
	if(hotFixLeave){

		// std::cout << "asdadsd\n";
		playerFightController.clearDamage();
		enemyFightController.clearDamage();
		hotFixLeave = false;
		atkOnce = false;
		enemyAtkOnce = false;
		return 3;
	}
	return -1;
}

int Battle::hotfixEffect(){

	std::string str;
	// std::cout << "t: " << t << "\n";

	if(m_player.m_HP == 0 || m_enemy.m_HP == 0) battleFinish = true;
	if(t == 0 && !battleFinish){

		if(playerFightController.effectType == Burn) str += "because of the burn, enemy's hp get down!\n";
		
		if(playerFightController.effectType == Poison) str += "because of the poison, enemy's hp get down!\n";

		if(playerFightController.buffType == Heal) str += "you get heal!\n";

		if(!flag){

			// if(playerFightController.buffDef) m_player.m_DEF += playerFightController.buffDef;
			if(playerFightController.debAtk)  m_enemy.m_ATK -= playerFightController.debAtk;
			if(playerFightController.debDef)  m_enemy.m_DEF -= playerFightController.debDef;
			if(playerFightController.debSpd)  m_enemy.m_SPD -= playerFightController.debSpd;

			if(playerFightController.effectType == Burn){
				
				str += "because of the burn, enemy's hp get down!\n";
				playerFightController.burnValue = origin_e.getHp()*0.08;
				m_enemy.m_HP -= playerFightController.burnValue;
			}
			if(playerFightController.effectType == Poison){

				str += "because of the poison, enemy's hp get down!\n";
				m_enemy.m_HP -= playerFightController.poisonValue;
				playerFightController.poisonValue += m_player.getLevel();
			}
			if(playerFightController.buffType == Heal){

				std::cout << "Heal!!!\n";
				str += "you get heal!\n";
				m_player.m_HP += m_player.getHp()*0.01;
			}
			if(str.size() == 0){

				t = 1;
				std::cout << "string size 0\n";
			}
			if(m_enemy.m_HP <= 0) m_enemy.m_HP = 0;
			playerFightController.init();
			flag = true;
		}

	}
	if(t == 1 && !battleFinish){
		
			if(enemyFightController.effectType == Burn) str += "because of the burn, your hp get down!\n";
			
			if(enemyFightController.effectType == Poison) str += "because of the poison, your hp get down!\n";
			
			if(enemyFightController.buffType == Heal) str += "enemy get heal\n";
			

		if(!flag2){
			
			if(enemyFightController.debAtk)  m_player.m_ATK -= enemyFightController.debAtk;
			if(enemyFightController.debDef)  m_player.m_DEF -= enemyFightController.debDef;
			if(enemyFightController.debSpd)  m_player.m_SPD -= enemyFightController.debSpd;

			if(enemyFightController.effectType == Burn){

				str += "because of the burn, enemy's hp get down!\n";
				enemyFightController.burnValue = origin_p.getHp()*0.08;
				m_player.m_HP -= enemyFightController.burnValue;
			}
			if(enemyFightController.effectType == Poison){

				str += "because of the poison, enemy's hp get down!\n";
				m_player.m_HP -= enemyFightController.poisonValue;
				enemyFightController.poisonValue += m_enemy.getLevel()/3;
			}
			if(enemyFightController.buffType == Heal){

				str += "enemy get heal\n";
				int heal = origin_e.getHp()*0.1;
				m_enemy.m_HP += heal;
				if(m_enemy.m_HP > origin_e.getHp()){

					m_enemy.m_HP = origin_e.getHp();
					std::cout << "reset" << "\n";
				}
			}
			if(str.size() == 0){

				t = 2;
				std::cout << "string size 0\n";
			}
			enemyFightController.init();
			flag2 = true;
		}
		if(m_player.m_HP <= 0) m_player.m_HP = 0;

	}
	if(t == 2 && !battleFinish){

		hotfixLeave2 = true;
	}

	if(m_player.m_ATK <= 0) m_player.m_ATK = 1;
	if(m_player.m_DEF <= 0) m_player.m_DEF = 1;
	if(m_player.m_SPD <= 0) m_player.m_SPD = 1;

	if(m_enemy.m_ATK <= 0) m_enemy.m_ATK = 1;
	if(m_enemy.m_DEF <= 0) m_enemy.m_DEF = 1;
	if(m_enemy.m_SPD <= 0) m_enemy.m_SPD = 1;

	if(hotfixLeave2){

		hotfixLeave2 = false;
		return 1;
	}

	if(str.size() == 0) {

		narration.setString("No effect\n");
	}
	else narration.setString(str);

	return -1;
}



Character Battle::effect(Character first, Character second, int who){

	if(who == 0){

		if(playerFightController.damaged > 0 ){

			// std::cout << "playyer: " << playerFightController.damaged << "\n";
			playerFightController.damaged--;
			m_enemy.m_HP--;
		} 

		if(m_enemy.m_HP == 0);

		if(playerFightController.buffAtk) m_player.m_ATK += playerFightController.buffAtk;
		if(playerFightController.buffDef) m_player.m_DEF += playerFightController.buffDef;
		if(playerFightController.buffSpd) m_player.m_SPD += playerFightController.buffSpd;

		if(playerFightController.effectType == Burn && !m_enemy.getNegStatus()) m_enemy.m_negStatus = Burn;
		if(playerFightController.effectType == Poison && !m_enemy.getNegStatus()) m_enemy.m_negStatus = Poison;
		if(playerFightController.buffType == Heal && !m_player.getPosStatus()) m_player.m_posStatus = Heal;

		playerFightController.init();
	}
	else{

		std::cout << "sss: " << enemyFightController.damaged << "\n";
		if(enemyFightController.damaged > 0) {

			// std::cout << "enemy" << enemyFightController.damaged << "\n";
			enemyFightController.damaged--;
			m_player.m_HP--;
		}
		

		if(m_enemy.m_HP == 0);

		if(enemyFightController.buffAtk) m_player.m_ATK += enemyFightController.buffAtk;
		if(enemyFightController.buffDef) m_player.m_DEF += enemyFightController.buffDef;
		if(enemyFightController.buffSpd) m_player.m_SPD += enemyFightController.buffSpd;

		if(enemyFightController.effectType == Burn && !m_player.getNegStatus()) m_player.m_negStatus = Burn;
		if(enemyFightController.effectType == Poison && !m_player.getNegStatus()) m_player.m_negStatus = Poison;
		if(enemyFightController.buffType == Heal && !m_enemy.getPosStatus()) m_enemy.m_posStatus = Heal;

		enemyFightController.init();
	}

}


bool Battle::finish(){

	if(m_player.getHp() == 0 || m_enemy.getHp() == 0){

		std::cout << "hp0" << "\n";
		return true;
	}

	return false;
}

bool Battle::playerWin(){

	if(m_enemy.getHp() == 0)
		return true;
	return false;
}

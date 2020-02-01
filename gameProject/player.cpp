#include "player.h"

Player::Player(){

	m_key = m_preKey = STOP;
	searchBattle = false;
	m_delay = 1;

	skillSet.push_back(allSkills.findSkillById(0));
	skillSet.push_back(allSkills.findSkillById(2));
	skillSet.push_back(allSkills.findSkillById(3));
	skillSet.push_back(allSkills.findSkillById(5));
	skillSet.push_back(allSkills.findSkillById(7));
	// skillSet.push_back(allSkills.findSkillById(10));
	skillCanLearn.push_back(std::pair<Skill, int>(allSkills.findSkillById(3), 8));
	skillCanLearn.push_back(std::pair<Skill, int>(allSkills.findSkillById(5), 16));
	skillCanLearn.push_back(std::pair<Skill, int>(allSkills.findSkillById(10), 28));
}

void Player::importMap(Map map){

	m_map = map;
	sticker.setMap(map);
}

void Player::learnSkill(int level){

	for(int i = 0 ; i < skillCanLearn.size() ; i++){

		if(skillCanLearn[i].second == level) skillSet.push_back(skillCanLearn[i].first);
	}
}

void Player::updateExp(int exp){

	while(exp--){

		m_EXP++;
		if(m_EXP == nextLevelExp){

			levelUp();
			learnSkill(m_LEVEL);
			m_EXP = 0;
			nextLevelExp = updateNextLevelExp();
		}
	}
}

void Player::stick(int x, int y, Character character){

	int index = m_map.getBlockIndex(x, y);
	sticker.stickCharacter(index, character);
}

void Player::setReadyBattle(Character character){

	readyBattle = character;
}

void Player::keyEvent(int state){

	int STATE = PLAY;

	switch(m_key){

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

			if(m_key != m_preKey){

				std::cout << "Z press" << "\n";
				switch(STATE){

					case PLAY:
						
						sf::Vector2f position = m_sprite.getPosition();
						switch(m_preDir){

							case UP:
								if(m_map.hasPeople(m_map.getBlockIndex(position.x, position.y)-38)){

									readyBattle = sticker.getCharacter(m_map.getBlockIndex(position.x, position.y) -38);
									readyBattle.setBattleSprite();
									searchBattle = true;
									std::cout << readyBattle.getHp() << "\n";
									std::cout << "True" << "\n";
								}
								else {

									searchBattle = false;
									std::cout << "False" << "\n";
								}
							break;
							case FORWARD:

								if(m_map.hasPeople(m_map.getBlockIndex(position.x, position.y)+1)){

									readyBattle = sticker.getCharacter(m_map.getBlockIndex(position.x, position.y) + 1);
									readyBattle.setBattleSprite();
									searchBattle = true;
									std::cout << readyBattle.getHp() << "\n";
									std::cout << "True" << "\n";
								}
								else {

									searchBattle = false;
									std::cout << "False" << "\n";
								}
							break;
							case BACKWARD:
								if(m_map.hasPeople(m_map.getBlockIndex(position.x, position.y)-1)){

									readyBattle = sticker.getCharacter(m_map.getBlockIndex(position.x, position.y) - 1);
									readyBattle.setBattleSprite();
									searchBattle = true;
									std::cout << readyBattle.getHp() << "\n";
									std::cout << "True" << "\n";
								}
								else {

									searchBattle = false;
									std::cout << "False" << "\n";
								}
							break;
							case DOWN:
								if(m_map.hasPeople(m_map.getBlockIndex(position.x, position.y)+38)){

									readyBattle = sticker.getCharacter(m_map.getBlockIndex(position.x, position.y) + 38);
									readyBattle.setBattleSprite();
									searchBattle = true;
									std::cout << readyBattle.getHp() << "\n";
									std::cout << "True" << "\n";
								}
								else {

									searchBattle = false;
									std::cout << "False" << "\n";
								}
							break;

						}
						
					break;
				}
			}
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

Character Player::getBattle(){

	return readyBattle;
}

bool Player::battle(){

	return searchBattle;
}

void Player::processInput(){

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

void Player::move(){

	if (m_delay == 1) m_delay = 0;

	int dir = checkDir();

	sf::Vector2f position = m_sprite.getPosition();
	int blockIndex = m_map.getBlockIndex(position.x, position.y);

	if (clock.getElapsedTime().asSeconds() > 0.1f){

		switch (dir){

			case STOP:
				if (DEBUG) std::cout << position.x << " " << position.y << " " << m_map.getBlockIndex(position.x, position.y) << "\n";
				animation(STOP);
				m_sprite.move(0, 0);
			break;
			case FORWARD:

				printf("Move Forward\n");
				animation(FORWARD);

				if (m_delay <= 0){
					
					if (!m_map.canWalk(blockIndex, FORWARD)) m_sprite.move(0, 0);
					else if (position.x >= 1160) m_sprite.move(0, 0);
					else m_sprite.move(32, 0);
				}

			break;
			case BACKWARD:
				printf("Move Backward\n");
				animation(BACKWARD);

				if (m_delay <= 0){
					
					if (!m_map.canWalk(blockIndex, BACKWARD)) m_sprite.move(0, 0);
					else if (position.x <= 0) m_sprite.move(0, 0);
					else m_sprite.move(-32, 0);
				}

			break;
			case UP:
				printf("Move UP\n");
				animation(UP);

				if (m_delay <= 0){

					if (!m_map.canWalk(blockIndex, UP)) m_sprite.move(0, 0);
					else if (position.y <= 0) m_sprite.move(0, 0);
					else m_sprite.move(0, -32);
				}

			break;
			case DOWN:
				printf("Move Down\n");
				animation(DOWN);

				if (m_delay <= 0){

					if (!m_map.canWalk(blockIndex, DOWN)) m_sprite.move(0, 0);
					else if (position.y >= 743) m_sprite.move(0, 0);
					else m_sprite.move(0, 32);
				}

			break;
			default:
				animation(STOP);
				m_sprite.move(0, 0);
			break;
		}
	}
	else{

		// printf("animation failed -> time: %f\n", clock.getElapsedTime().asSeconds());
	}
	m_delay++;
}

void Player::update(){

	if (m_dir != STOP) m_preDir = m_dir;

	searchBattle = false;
	m_preKey = m_key;
	// std::cout << m_preKey << " " << m_key << "\n";
	m_sprite.setTextureRect(m_rectSourceSprite);
	// std::cout << m_sprite.getPosition().x << " " << m_sprite.getPosition().y << "\n";
}

void Player::setBattleSprite(){

	m_battleSprite.setTexture(m_texture);
	m_battleSprite.setTextureRect(sf::IntRect(0, 77*3, 77, 77));
	m_battleSprite.setScale(2.0f, 2.0f);
	m_battleSprite.setPosition(350, 450);
}

void Player::conquer(){

	sf::Vector2f position = m_sprite.getPosition();
	switch(m_preDir){

		case UP:
			if(m_map.hasPeople(m_map.getBlockIndex(position.x, position.y)-38)){

				sticker.access(m_map.getBlockIndex(position.x, position.y)-38);
			}
		break;
		case FORWARD:

			if(m_map.hasPeople(m_map.getBlockIndex(position.x, position.y)+1)){

				sticker.access(m_map.getBlockIndex(position.x, position.y)+1);
			}
		break;
		case BACKWARD:
			if(m_map.hasPeople(m_map.getBlockIndex(position.x, position.y)-1)){

				sticker.access(m_map.getBlockIndex(position.x, position.y)-1);
			}
		break;
		case DOWN:
			if(m_map.hasPeople(m_map.getBlockIndex(position.x, position.y)+38)){

				sticker.access(m_map.getBlockIndex(position.x, position.y)+38);
			}
		break;

	}
}

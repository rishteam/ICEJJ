#pragma once
#include "character.h"
#include <iostream>

Character::Character(){

	// std::cout << "Character one" << "\n";
	m_rectSourceSprite = sf::IntRect(0, 0, 77, 77);
	m_preDir = STOP;
	m_dir = STOP;

	m_valid = true;
	m_collision = false;
	// m_delay = 1;
}

Character::Character(int face){

	face -= 1;
	int y_pos = face*77;


	m_rectSourceSprite = sf::IntRect(0, y_pos, 77, 77);
	std::cout << "Character two" << "\n";
	m_preDir = STOP;
	m_dir = STOP;

	m_valid = true;
	m_collision = false;
	// m_delay = 1;
}

Character::Character(sf::Texture texture, sf::Sprite sprite, int face){

	std::cout << "Character three" << "\n";
	face -= 1;
	int y_pos = face * 77;

	m_sprite = sprite;
	m_texture = texture;
	m_rectSourceSprite = sf::IntRect(0, y_pos, 77, 77);
	m_preDir = STOP;
	m_dir = STOP;

	m_valid = true;
	m_collision = false;
	// m_delay = 1;
}

void Character::setPosition(int x, int y){

	m_sprite.setPosition(x, y);
}

void Character::setDir(int dir){

	m_dir = dir;
}

int Character::checkDir(){

	if(m_dir != STOP){

		if(m_preDir != m_dir)
			m_rectSourceSprite = sf::IntRect(0, (m_dir-1)*77, 77, 77);
	}

	return m_dir;
}

void Character::collide(Character character){

	if(m_sprite.getPosition().x >= character.m_sprite.getPosition().x && m_sprite.getPosition().x <= character.m_sprite.getPosition().x+20){

		if(m_sprite.getPosition().y >= character.m_sprite.getPosition().y && m_sprite.getPosition().y <= character.m_sprite.getPosition().y+30){

			// std::cout << "Collision" << "\n";
			m_collision = true;
		}
	}
	else m_collision = false;
}


void Character::move(){

	// if (m_delay == 1) m_delay = 0;

	int dir = checkDir();

	sf::Vector2f position = m_sprite.getPosition();
	// int blockIndex = m_map.getBlockIndex(position.x, position.y);

	if (clock.getElapsedTime().asSeconds() > 0.1f){

		switch (dir){

			case STOP:
				// if (DEBUG) std::cout << position.x << " " << position.y << " " << m_map.getBlockIndex(position.x, position.y) << "\n";
				animation(STOP);
				m_sprite.move(0, 0);
			break;
			case FORWARD:

				printf("Move Forward\n");
				animation(FORWARD);


				// if (!m_map.canWalk(blockIndex, FORWARD)) m_sprite.move(0, 0);
				if (position.x >= 1160) m_sprite.move(0, 0);
				else m_sprite.move(32, 0);
				

			break;
			case BACKWARD:
				printf("Move Backward\n");
				animation(BACKWARD);


				// if (!m_map.canWalk(blockIndex, BACKWARD)) m_sprite.move(0, 0);
				if (position.x <= 0) m_sprite.move(0, 0);
				else m_sprite.move(-32, 0);
				

			break;
			case UP:
				printf("Move UP\n");
				animation(UP);



				// if (!m_map.canWalk(blockIndex, UP)) m_sprite.move(0, 0);
				if (position.y <= 0) m_sprite.move(0, 0);
				else m_sprite.move(0, -32);
				

			break;
			case DOWN:
				printf("Move Down\n");
				animation(DOWN);



				// if (!m_map.canWalk(blockIndex, DOWN)) m_sprite.move(0, 0);
				if (position.y >= 743) m_sprite.move(0, 0);
				else m_sprite.move(0, 32);
				

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
	// m_delay++;
}

void Character::animation(int animate){

	if(animate == STOP){

		if(m_preDir == BACKWARD || m_preDir == FORWARD) {

			m_rectSourceSprite.left = 539;
		}
	
		else m_rectSourceSprite.left = 0;
	}
	else
		m_rectSourceSprite.left += interval;


	if(m_rectSourceSprite.left >= 616){

		m_rectSourceSprite.left = 0;
	}
	clock.restart();
}

void Character::update(){

	if(m_dir != STOP) m_preDir = m_dir;
	
	m_sprite.setTextureRect(m_rectSourceSprite);
}

void Character::createSprite(std::string str){

	loadImage(str);
	m_sprite.setTexture(m_texture);
	m_sprite.setTextureRect(m_rectSourceSprite);
	m_sprite.setScale(0.6f, 0.6f);
}

void Character::loadImage(std::string str){

	if(!m_texture.loadFromFile(str)) printf("Failed to loadImage\n");
	
	else printf("Sucess to load Image\n");
}


bool Character::isCharacterValid(){

	return m_valid;
}

sf::Sprite Character::show(){

	return m_sprite;
}

Skill Character::getSkill(int index){

	if(skillSet.size() < index){

		std::cout << "such skill not found" << "\n";
		return Skill("bug招", 200, 100, "?????", -1, Poison);
	}
	else return skillSet[index];
}


int Character::getSkillsetSize(){

	return skillSet.size();
}

sf::Sprite Character::getBattleSprite(){

	return m_battleSprite;
}

void Character::setBattleSprite(){

	m_battleSprite.setTexture(m_texture);
	m_battleSprite.setTextureRect(sf::IntRect(0, 0, 77, 77));
	m_battleSprite.setScale(1.2f, 1.2f);
	m_battleSprite.setPosition(700, 60);
}
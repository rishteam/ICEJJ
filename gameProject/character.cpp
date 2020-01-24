#include "character.h"
#include <iostream>

Character::Character(){

	m_rectSourceSprite = sf::IntRect(0, 0, 77, 77);
	m_preDir = STOP;
	m_dir = STOP;
}

Character::Character(sf::Texture texture, sf::Sprite sprite, int face){

	face -= 1;
	int y_pos = face * 77;

	m_sprite = sprite;
	m_texture = texture;
	m_rectSourceSprite = sf::IntRect(0, y_pos, 77, 77);
	m_preDir = STOP;
	m_dir = STOP;
}

int Character::checkDir(){

	if(m_dir != STOP){

		if(m_preDir != m_dir)
			m_rectSourceSprite = sf::IntRect(0, (m_dir-1)*77, 77, 77);
	}

	return m_dir;
}

void Character::move(){

	int dir = checkDir();

	sf::Vector2f position = m_sprite.getPosition();

	// printf("%d %d\n", position.x, position.y);
	std::cout << position.x << " " << position.y << std::endl;

	if (clock.getElapsedTime().asSeconds() > 0.03f){

		printf("In move, dir:%d \n", dir);
		switch (dir){

			case STOP:
				printf("Stop\n");
				animation(STOP);
				m_sprite.move(0, 0);
			break;
			case FORWARD:
				printf("Move Forward\n");
				animation(FORWARD);
				
				if(position.x >= 1140) m_sprite.move(0, 0);
				else m_sprite.move(10, 0);
			break;
			case BACKWARD:
				printf("Move Backward\n");
				animation(BACKWARD);

				if(position.x <= -10) m_sprite.move(0,0);
				else m_sprite.move(-10, 0);
			break;
			case UP:
				printf("Move UP\n");
				animation(UP);

				if(position.y <= 0) m_sprite.move(0, 0);
				else m_sprite.move(0, -10);
			break;
			case DOWN:
				printf("Move Down\n");
				animation(DOWN);

				if(position.y >= 720) m_sprite.move(0, 0);
				else m_sprite.move(0, 10);
			break;
			default:
				printf("In default\n");
				animation(STOP);
				m_sprite.move(0, 0);
			break;
		}
	}
	else{

		printf("animation failed -> time: %f\n", clock.getElapsedTime().asSeconds());
	}
}

void Character::animation(int animate){

	printf("animate\n");

	if(animate == STOP){

		if(m_preDir == BACKWARD || m_preDir == FORWARD){

			printf("In\n");
			m_rectSourceSprite.left = 539;
		}
		else
			m_rectSourceSprite.left = 0;
	}
	else
		m_rectSourceSprite.left += interval;


	if(m_rectSourceSprite.left >= 616){

		m_rectSourceSprite.left = 0;
	}
	clock.restart();
}

void Character::update(){

	if(m_dir != STOP)
		m_preDir = m_dir;
	
	m_sprite.setTextureRect(m_rectSourceSprite);
}

void Character::createSprite(std::string str){

	loadImage(str);
	m_sprite.setTexture(m_texture);
	m_sprite.setTextureRect(m_rectSourceSprite);
}

void Character::loadImage(std::string str){

	if(!m_texture.loadFromFile(str)){

		printf("Failed to loadImage\n");
	}
}


sf::Sprite Character::show(){

	return m_sprite;
}




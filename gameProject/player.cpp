#include "player.h"

void Player::setDir(int dir){

	m_dir = dir;
}

void Player::keyEvent(){

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

void Player::update(){

	printf("update\n");
	if (m_dir != STOP)
		m_preDir = m_dir;

	m_preKey = m_key;
	m_sprite.setTextureRect(m_rectSourceSprite);
}


#include "player.h"

Player::Player(){

	m_key = m_preKey = STOP;
	m_talk = false;
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
			std::cout << "Z press" << "\n";
			switch(STATE){

				case PLAY:
					
					sf::Vector2f position = m_sprite.getPosition();
					switch(m_preDir){

						case UP:

						break;
						case FORWARD:

							if(m_map.hasPeople(m_map.getBlockIndex(position.x, position.y)+1)) std::cout << "True" << "\n";
							else std::cout << "False" << "\n";

						break;
					}
					
				break;
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

	if (m_dir != STOP) m_preDir = m_dir;

	m_preKey = m_key;
	m_sprite.setTextureRect(m_rectSourceSprite);
	// std::cout << m_sprite.getPosition().x << " " << m_sprite.getPosition().y << "\n";
}


#include "npc.h"

NPC::NPC(){

	m_movementLen = 0;
	m_movementIndex = 0;
	counter = 1;
	delayTime = 50;
}

NPC::NPC(int time){

	m_movementLen = 0;
	m_movementIndex = 0;
	counter = 1;
	delayTime = time;
}

void NPC::setDelay(int time){

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

void NPC::update(){

	if(m_dir != STOP) m_preDir = m_dir;
	m_sprite.setTextureRect(m_rectSourceSprite);

	delay();
	if(!counter) m_movementIndex++;
	if(m_movementIndex == m_movementLen) m_movementIndex = 0;
}
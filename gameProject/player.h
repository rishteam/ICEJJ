#pragma once
#include "character.h"

class  Player: public Character{


public:

	Player();

	// void collide(NPC npc);
	void processInput();
	void update();
	void keyEvent(int state);
	// void move();


private:

	int m_preKey;
	int m_key;
	int m_delay;

	bool m_talk;
};
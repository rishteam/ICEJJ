#include "character.h"

class NPC : public Character{

public:

	NPC();
	NPC(int face);
	NPC(float delay);

	void setDelay(float time);
	void update();
	void setNPCMovement(int loop[], int len);
	void processInput();
	void createSprite(int type);
	void setSkill(int type);
	void setBattleSprite();

private:

	void delay();
	void checkMovementValid(int loop[], int len);
	int m_movementLen;
	int m_movementIndex;

	float delayTime;
	int counter;
	int provideExp;
	int m_type;

	std::vector<int> m_movement;

};





#include "character.h"

class NPC : public Character{

public:

	NPC();
	NPC(int delay);

	void setDelay(int time);
	void update();
	void setNPCMovement(int loop[], int len);
	void processInput();

private:

	void delay();
	void checkMovementValid(int loop[], int len);
	int m_movementLen;
	int m_movementIndex;

	int delayTime;
	int counter;


	std::vector<int> m_movement;

};





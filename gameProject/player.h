#include "character.h"

class  Player: public Character{

public:

	void processInput();
	void update();
	void keyEvent();
	void setDir(int dir);

private:

	int m_preKey;
	int m_key;
};
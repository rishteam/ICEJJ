#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "player.h"
#include "npc.h"
#include "tilemap.h"
#include "map.h"
#include "battle.h"
#include <iostream>

const int level[] ={
	
	2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
	2, 0, 2, 2, 2, 2, 0, 0, 2, 2, 0, 0, 0, 0, 1, 1, 2, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 1, 1, 1, 1, 1,
	2, 0, 0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 2, 0, 1, 1, 2, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 1, 1, 1, 1, 1,
	2, 2, 2, 2, 2, 2, 0, 2, 2, 2, 2, 2, 2, 0, 2, 2, 2, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 1, 1, 1, 1, 1,
	2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
	2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
	2, 2, 3, 2, 2, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 1, 1, 1, 1, 1,
	2, 2, 3, 2, 2, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 1, 1, 1, 1, 1,
	2, 2, 3, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 1, 1, 1, 1, 1,
	2, 2, 3, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 1, 1, 1, 1, 1,
	2, 2, 3, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 1, 1, 1, 1, 1,		
	
	2, 2, 3, 0, 0, 2, 2, 2, 2, 2, 2, 2, 2, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 1, 1, 1,
	2, 2, 3, 2, 0, 0, 2, 2, 2, 2, 0, 0, 0, 0, 1, 1, 2, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 1, 1, 1, 1, 1,
	2, 2, 2, 2, 2, 0, 2, 2, 2, 2, 2, 2, 2, 0, 1, 1, 2, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 1, 1, 1, 1, 1,
	2, 2, 2, 2, 2, 0, 0, 2, 2, 2, 2, 2, 2, 0, 2, 2, 2, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 1, 1, 1, 1, 1,
	2, 2, 2, 2, 2, 2, 2, 0, 2, 2, 2, 2, 2, 2, 2, 0, 2, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
	2, 2, 2, 0, 0, 0, 0, 2, 2, 2, 2, 2, 2, 2, 0, 0, 0, 2, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 1, 1, 1, 1, 1,
	2, 2, 2, 2, 2, 2, 0, 2, 2, 2, 1, 1, 1, 1, 1, 1, 0, 2, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 2, 1, 1, 1, 1, 1,
	2, 2, 0, 2, 2, 2, 0, 2, 2, 2, 1, 1, 1, 1, 1, 1, 2, 2, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 2, 1, 1, 1, 1, 1,
	2, 2, 0, 1, 2, 2, 0, 2, 2, 2, 1, 1, 1, 1, 1, 1, 0, 2, 0, 1, 1, 1, 1, 1, 1, 0, 0, 1, 0, 1, 0, 0, 2, 1, 1, 1, 1, 1,
	2, 2, 2, 1, 2, 0, 2, 2, 2, 2, 1, 1, 1, 1, 1, 1, 0, 2, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 1, 0, 0, 2, 1, 1, 1, 1, 1,
	2, 2, 0, 1, 2, 0, 2, 2, 2, 2, 1, 1, 1, 1, 1, 1, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 2, 1, 1, 1, 1, 1,
	2, 2, 2, 1, 2, 0, 2, 2, 2, 2, 1, 1, 1, 1, 1, 1, 0, 2, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 1, 0, 0, 2, 1, 1, 1, 1, 1,
	2, 2, 0, 1, 2, 0, 2, 2, 2, 2, 1, 1, 1, 1, 1, 1, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 2, 1, 1, 1, 1, 1,
	2, 2, 0, 1, 2, 0, 2, 2, 2, 2, 1, 1, 1, 1, 1, 1, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 2, 1, 1, 1, 1, 1,
};

int STATE = PLAY;

int main(){

	//create a window
	sf::RenderWindow window(sf::VideoMode(1200, 800), "project");
	// window.setSize(sf::Vector2u(1200, 800));
	window.setFramerateLimit(120);


	Map mp(level, 38, 25);

	NPC npc(BACKWARD);
	npc.createSprite(ENEMYHEA);

	int move[] = {STOP};
	npc.setNPCMovement(move, 1);
	npc.setPosition(473, 103);
	mp.setNPCPos(473, 103);

	// npc.importMap(mp);

	TileMap map;
	if (!map.load("tileset.png", sf::Vector2u(32, 32), level, 38, 25))
		return -1;

	Player mainActor;
	mainActor.createSprite("data/picture/character/mainCh.png");
	mainActor.setPosition(441, 103);
	mainActor.importMap(mp);
	mainActor.stick(473, 103, npc);

	//bring window to life
	while(window.isOpen()){

		//event handle
		sf::Event event;
		
		while(window.pollEvent(event)){

			if(event.type == sf::Event::Closed)
				window.close();
		}


		switch(STATE){

			case PLAY:
				mainActor.processInput();
				mainActor.keyEvent(PLAY);
				mainActor.move();

				npc.processInput();
				npc.move();	

				npc.update();
				if(mainActor.battle()) STATE = BATTLE;
				
				mainActor.update();


				window.clear(sf::Color::White);
				window.draw(map);
				window.draw(npc.show());
				window.draw(mainActor.show());
			break;

			case BATTLE:
				std::cout << "In Battle" << "\n";
				std::cout << mainActor.getSkill(0).getId() << "\n";
				Battle battle(mainActor, mainActor.getBattle());
				mainActor.setBattleSprite();
				npc.setBattleSprite();


				while(1){
					
					while(window.pollEvent(event)){

						if(event.type == sf::Event::Closed)
							window.close();
					}

					battle.setText();


					window.clear(sf::Color::Green);
					window.draw(battle.getTextBar());
					window.draw(battle.getHpBar());
					window.draw(battle.getSkillBar());
					window.draw(battle.getEnemyHpBar());

					window.draw(mainActor.getBattleSprite());
					window.draw(npc.getBattleSprite());

					window.draw(battle.getEnemyData());
					window.draw(battle.getPlayerDataHp());
					window.draw(battle.getPlayerDataExp());

					for(int i = 0 ; i < battle.getSkill().size() ; i++){

						window.draw(battle.getSkill()[i]);
					}

					window.display();
				}

			break;

		}

		window.display();
	}

	return 0;
}

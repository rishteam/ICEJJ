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
	npc.setAbilities(70, 210, 99, 128, 90);
	int move[] = {STOP};
	npc.setNPCMovement(move, 1);
	npc.setPosition(473, 103);
	mp.setNPCPos(473, 103);

	NPC boss(BACKWARD);
	boss.createSprite(Boss);
	boss.setAbilities(85, 420, 100, 150, 20);
	boss.setNPCMovement(move,1);
	boss.setPosition(985, 103);
	mp.setNPCPos(985, 103);

	NPC npc2(DOWN);
	npc2.createSprite(ENEMYATK);
	npc2.setAbilities(72, 152, 250, 122, 80);
	npc2.setNPCMovement(move,1);
	npc2.setPosition(25, 7);
	mp.setNPCPos(25, 7);

	NPC npc3(UP);
	npc3.createSprite(ENEMYDEF);
	npc3.setAbilities(70, 300, 80, 230, 10);
	npc3.setNPCMovement(move,1);
	npc3.setPosition(57, 359);
	mp.setNPCPos(57, 359);

	// npc.importMap(mp);

	TileMap map;
	if (!map.load("tileset.png", sf::Vector2u(32, 32), level, 38, 25))
		return -1;

	Player mainActor;
	mainActor.createSprite("data/picture/character/mainCh.png");
	mainActor.setPosition(441, 103);
	mainActor.importMap(mp);
	mainActor.stick(473, 103, npc);
	mainActor.stick(985, 103, boss);
	mainActor.stick(25, 7, npc2);
	mainActor.stick(57, 359, npc3);
	mainActor.setAbilities(78, 323, 201, 102, 300);
	mainActor.setBattleSprite();
	npc.setBattleSprite();
	boss.setBattleSprite();
	npc2.setBattleSprite();
	npc3.setBattleSprite();

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

				npc2.processInput();
				npc2.move();
				npc2.update();

				boss.processInput();
				boss.move();
				boss.update();

				npc3.processInput();
				npc3.move();
				npc3.update();

				if(mainActor.battle()) {

					if(mainActor.getBattle().canBattle)
						STATE = BATTLE;
				}
				
				mainActor.update();

				window.clear(sf::Color::White);
				window.draw(map);
				window.draw(npc.show());
				window.draw(npc2.show());
				window.draw(boss.show());
				window.draw(npc3.show());
				window.draw(mainActor.show());
			break;

			case BATTLE:

				while(sf::Keyboard::isKeyPressed(sf::Keyboard::Z)){
				};

				std::cout << "In Battle" << "\n";
				// mainActor.setReadyBattle(boss);
				Battle battle(mainActor, mainActor.getBattle());
				// battle.processInput();

				int state = STRATEGY;
				bool leave = false;

				while(1){
					
					while(window.pollEvent(event)){

						if(event.type == sf::Event::Closed)
							window.close();
					}


					switch(state){


						case STRATEGY:
							// std::cout << "Strategy\n";
							battle.processInput();
							battle.keyEvent(STRATEGY);
							battle.setText(); 
							battle.setNarration("choose skill\n");
							if(battle.toExe) state = EXECUTE;
							battle.toExe = false;
						break;
						case EXECUTE:
							// std::cout << "Execute\n";
							battle.processInput();
							battle.keyEvent(EXECUTE);
							if (battle.hotfixfight() == 3){

								state = EFFECT;
							}
							else if (battle.hotfixfight() == -1) {

								state = EXECUTE;
							}
							battle.setText();
							if(battle.battleFinish){

								state = FINISH;
								battle.battleFinish = false;
							}
						break;
						case EFFECT:
							// std::cout << "Effect\n" << "\n";
							battle.processInput();	
							battle.keyEvent(EFFECT);
							if(battle.hotfixEffect() == 1){

								std::cout << "meow\n";
								state = STRATEGY;
							}
							else state = EFFECT;

							if(battle.battleFinish){

								state = FINISH;
								battle.battleFinish = false;
							}
							battle.setText();
							
						break;
						case FINISH:

							if(battle.playerWin()) {
								
								mainActor.conquer();
								battle.setNarration("You Win!\nPress X leave");
							}
							else battle.setNarration("You Lose!\nPress X leave");

							if(sf::Keyboard::isKeyPressed(sf::Keyboard::X)){
								
								if(battle.finish()) STATE = PLAY;
								leave = true;
							}
						break;
					}

					// std::cout << "qweqwe" << "\n";
					window.clear(sf::Color::Green);
					window.draw(battle.getTextBar());
					window.draw(battle.getHpBar());
					window.draw(battle.getSkillBar());
					window.draw(battle.getEnemyHpBar());
					window.draw(battle.getDescriptionBar());
					window.draw(battle.getChooseBar());

					window.draw(mainActor.getBattle().getBattleSprite());
					window.draw(battle.getPlayerSprite());

					window.draw(battle.getEnemyData());
					window.draw(battle.getPlayerDataHp());
					// window.draw(battle.getPlayerDataExp());
					window.draw(battle.getDescription());
					window.draw(battle.getPlayerStatus());
					window.draw(battle.getEnemyStatus());
					window.draw(battle.getNarration());
					// window.draw(mainActor.getBattle().show());

					for(int i = 0 ; i < battle.getSkill().size() ; i++){

						window.draw(battle.getSkill()[i]);
					}

					window.display();
					if(leave) break;
				}

			break;

		}

		window.display();
	}

	return 0;
}

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "player.h"

#include <iostream>


int main(){

	//create a window
	sf::RenderWindow window(sf::VideoMode(1200, 800), "project");
	// window.setSize(sf::Vector2u(1200, 800));
	window.setFramerateLimit(120);

	Player mainActor;
	mainActor.createSprite("data/picture/character/mainCh.png");

	//bring window to life
	while(window.isOpen()){

		//event handle
		sf::Event event;
		
		while(window.pollEvent(event)){

			if(event.type == sf::Event::Closed)
				window.close();
		}

		mainActor.processInput();
		mainActor.keyEvent();
		mainActor.move();
		mainActor.update();

		window.clear(sf::Color::White);
		window.draw(mainActor.show());
		window.display();

	}

	return 0;
}

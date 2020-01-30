#include "battle.h"

Bar::Bar(){

	hpBar.setSize(sf::Vector2f(400,68));
	enemyHpBar.setSize(sf::Vector2f(400, 100));
	skillBar.setSize(sf::Vector2f(500, 150));
	textBar.setSize(sf::Vector2f(798, 80));

	hpBar.setOutlineColor(sf::Color::Black);
	hpBar.setOutlineThickness(2);
	hpBar.setPosition(900, 580);

	textBar.setOutlineColor(sf::Color::Black);
	textBar.setOutlineThickness(1);
	textBar.setPosition(0, 720);

	skillBar.setOutlineColor(sf::Color::Black);
	skillBar.setOutlineThickness(2);
	skillBar.setPosition(800, 650);
	skillBar.setFillColor(sf::Color(0, 0, 0, 128));

	enemyHpBar.setOutlineColor(sf::Color::Red);
	enemyHpBar.setOutlineThickness(3);
	enemyHpBar.setPosition(0, 0);
	if (!font.loadFromFile("data/font/arial.ttf"))
	{
	}

	for(int i = 0 ; i < 6 ; i++){

		sf::Text tmp;

		if(i < 3) tmp.setPosition(820, i*50 + 660);
		else tmp.setPosition(1020, (i-3)*50 + 660);

		tmp.setFont(font);
		tmp.setFillColor(sf::Color::Black);
		tmp.setCharacterSize(24);
		tmp.setString("");
		textArr.push_back(tmp);
	}
	// enemyData = setTextAttr(font, 44, sf::Color::Black);
	// playerDataHp = setTextAttr(font, 26, sf::Color::Black);
	// playerDataExp = setTextAttr(font, 24, sf::Color::Black);

	enemyData.setFont(font);
	enemyData.setFillColor(sf::Color::Black);
	enemyData.setCharacterSize(44);
	enemyData.setPosition(230, 40);

	playerDataHp.setFont(font);
	playerDataHp.setFillColor(sf::Color::Black);
	playerDataHp.setCharacterSize(44);
	playerDataHp.setPosition(1040, 600);

	playerDataExp.setFont(font);
	playerDataExp.setFillColor(sf::Color::Blue);
	playerDataExp.setCharacterSize(38);
	playerDataExp.setPosition(1090, 530);
}

sf::Text Bar::setTextAttr(sf::Font font, int size, sf::Color color){

	sf::Text tmp;
	tmp.setFont(font);
	tmp.setCharacterSize(size);
	tmp.setFillColor(color);
	return tmp;
}

std::vector<sf::Text> Bar::getSkill(){

	return textArr;
}

sf::Text Bar::getEnemyData(){

	return enemyData;
}

sf::Text Bar::getPlayerDataExp(){

	return playerDataExp;
}

sf::Text Bar::getPlayerDataHp(){

	return playerDataHp;
}

sf::RectangleShape Bar::getHpBar(){

	return hpBar;
}

sf::RectangleShape Bar::getEnemyHpBar(){

	return enemyHpBar;
}

sf::RectangleShape Bar::getSkillBar(){

	return skillBar;
}

sf::RectangleShape Bar::getTextBar(){

	return textBar;
}

Battle::Battle(Character player, Character enemy){

	origin_p = m_player = player;
	origin_e = m_enemy = enemy;

}

void Battle::setText(){

	// enemyData.setString("FFFF");
	enemyData.setString(std::to_string(m_enemy.getHp()) + " / " + std::to_string(origin_e.getHp()));
	playerDataHp.setString(std::to_string(m_player.getHp()) + " / " + std::to_string(origin_p.getHp()));
	playerDataExp.setString( std::to_string(m_player.getExp()) + " / " + std::to_string(origin_p.getExp()));
	
	for(int i = 0 ; i < origin_p.getSkillsetSize(); i++) textArr[i].setString(origin_p.getSkill(i).getName()); 
}

void Battle::setTool(){

	
}

void Battle::draw(sf::RenderWindow window){


}
#ifndef PLAYERATTRIBUTE_H
#define PLAYERATTRIBUTE_H

#include "Player.h"

class Attributes
{
	private:
	Player* player;
	sf::Text text;
	sf::Font font;
	
	public : 
	Attributes(Player* player);
	void update(float dt);
	void render(sf::RenderWindow* window);
};
#endif
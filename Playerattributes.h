#ifndef PLAYERATTRIBUTE_H
#define PLAYERATTRIBUTE_H

#include "Player.h"
#include "string"
class Attributes
{
	private:
	Player* player;
	sf::Text text;
	sf::Font font;
	std::string s;
	float pos;
	sf::RectangleShape health;
	public : 
	Attributes(Player* player,std::string s,float pos);
	virtual ~Attributes();
	void initHealth();
	void initScore();
	void update(float dt);
	void render(sf::RenderWindow* window);
};
#endif
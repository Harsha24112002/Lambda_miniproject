#include "Playerattributes.h"
#include <iostream>
Attributes::Attributes(Player* player,std::string s,float pos)
{
	this->player=player;
	this->pos=pos;
	this->initHealth();
	this->s =s;
	this->initScore();
	this->font.loadFromFile("HOMOARAK.TTF");
	
	this->text.setFont(font);
	this->text.setCharacterSize(30);
	this->text.setPosition(sf::Vector2f(1500,pos+100));
	this->text.setFillColor(player->getcolor());
}
Attributes::~Attributes()
{

}
void Attributes::initHealth()
{
	health.setSize(sf::Vector2f(player->getkill()*40,20));
	health.setPosition(sf::Vector2f(1500,pos));
	health.setFillColor(player->getcolor());
}
void Attributes::initScore()
{
	std::string a;
	a=s+std::to_string(player->getscore());
	text.setString(a);
}
void Attributes::update(float dt)
{
	std::string a;
	a=s+std::to_string(player->getscore());
	text.setString(a);
	health.setSize(sf::Vector2f(player->getkill()*40,20));
}

void Attributes::render(sf::RenderWindow* window)
{
	
	window->draw(health);
	window->draw(text);
}
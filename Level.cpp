#include "Level.h"
#include <iostream>
Level::Level(sf::Texture* Texture,sf::Texture* exp, std::string s,std::vector<Enemy*>* enemies):enemies(enemies)
{
	this->levels=levels;
	this->Texture=Texture;
	this->enembultex=exp;
	this->filename=s;
	complete=false;
}
Level::~Level()
{
	
}
void Level::start()
{
	std::fstream file;
	file.open(filename);
	if(file.is_open())
	{
		float a,b;
		while(file>>a>>b)
		{

		enemies->push_back(new Enemy(Texture,sf::Vector2f(a,b),enembultex));
		}
		
	}
	file.close();
}
bool Level::getlevel()
{
	return complete;
}
void Level::update()
{
	if(this->enemies->empty())
	{
		complete=true;
	}
}
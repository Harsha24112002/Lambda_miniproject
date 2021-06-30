#include "Level.h"
#include <iostream>
Level::Level(sf::Texture* Texture,std::list<Level*>* levels,std::vector<Enemy*>* enemies):enemies(enemies)
{
	this->levels=levels;
	this->Texture=Texture;
	
	complete=false;
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
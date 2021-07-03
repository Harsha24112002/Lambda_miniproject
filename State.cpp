#include "State.h"
#include <iostream>
state::state(sf::RenderWindow* window,std::stack<state*>* states)
{
	this->window=window;
	this->states=states;
	this->Mousepos={0,0};
	textures["PLAYER"]=new sf::Texture();
	textures["PLAYER"]->loadFromFile("spaceship.png");
	textures["ENEMY"]= new sf::Texture();
	textures["ENEMY"]->loadFromFile("spaceship.png");
	textures["BULLET"]=new sf::Texture();
	textures["BULLET"]->loadFromFile("laserBullet.png");
	textures["ENEMYBULLET"]=new sf::Texture();
	textures["ENEMYBULLET"]->loadFromFile("new_bullet.png");
	textures["SHIELD"]=new sf::Texture();
	textures["SHIELD"]->loadFromFile("shield.png");
	textures["INVISIBLE"]=new sf::Texture();
	textures["INVISIBLE"]->loadFromFile("invisible.png");
	textures["MEDICINE"]= new sf::Texture();
	textures["MEDICINE"]->loadFromFile("health.png");
	textures["EXPLOSION"]= new sf::Texture();
	textures["EXPLOSION"]->loadFromFile("exp2_0.png");
	textures["BACKGROUND"]=new sf::Texture();
	textures["BACKGROUND"]->loadFromFile("spacebackground.jpeg");
	this->quit=false;
}
state::~state()
{
	for(auto& a:textures)
	{
		delete a.second;
	}
}

void state::Mouseposupdate()
{
	this->Mousepos=sf::Mouse::getPosition(*window);
}	
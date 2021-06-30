#include "State.h"

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
	this->quit=false;
}
state::~state()
{
	
}

void state::Mouseposupdate()
{
	this->Mousepos=sf::Mouse::getPosition(*window);
}	
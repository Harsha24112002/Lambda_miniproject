#include "Mainmenustate.h"
#include "Levelone.h"
#include <iostream>
Mainmenustate::Mainmenustate(sf::RenderWindow* window,std::stack<state*>* states):state(window,states)
{
	this->initialisebuttons();
}

Mainmenustate::~Mainmenustate()
{
	
}

void Mainmenustate::initialisebuttons()
{
	buttons["GAME"]=new Option("Single",sf::Vector2f(window->getSize().x/2.0f-250,window->getSize().y/2.0f-200),sf::Vector2f(250,100));
	buttons["DUO"]=new Option("Dual",sf::Vector2f(window->getSize().x/2.0f-250,window->getSize().y/2.0f-100),sf::Vector2f(250,100));
	buttons["Exit"]=new Option("Exit",sf::Vector2f(window->getSize().x/2.0f-250,window->getSize().y/2.0f-0),sf::Vector2f(250,100));
}

void Mainmenustate::update(float dt)
{
	this->Mouseposupdate();
	for(auto& a: buttons)
	{
		a.second->update(Mousepos);
	}
	if(buttons["GAME"]->buttonpressed())
	{
		
		states->push(new Singleplayer(window,states));
	}
	if(buttons["Exit"]->buttonpressed())
	{
		this->endstate();
	}
	if(buttons["DUO"]->buttonpressed())
	{
		states->push(new Dualplayer(window,states));
	}
	

}
void Mainmenustate::render()
{
	for(auto&a : buttons)
	{
		a.second->render(window);
	}
}

#include "Gameover.h"
#include <iostream>
Gameover::Gameover(sf::RenderWindow* window,std::stack<state*>* states,bool *quit):state(window,states),gamestatequit(quit)
{
	this->initButtons();
}

void Gameover::initButtons()
{
	
	buttons["QUIT"]=new Option("QUIT",sf::Vector2f(window->getSize().x/2,window->getSize().y/2-300),sf::Vector2f(150,100));	
}

void Gameover::update(float dt)
{
	this->Mouseposupdate();
	for(auto& a:buttons)
	{	
		a.second->update(Mousepos);
	}
	
	if(buttons["QUIT"]->buttonpressed())
	{
		*gamestatequit=true;
		this->endstate();	
	}
}

void Gameover::render()
{
	for(auto& a:buttons)
	{
		a.second->render(window);
	}
}
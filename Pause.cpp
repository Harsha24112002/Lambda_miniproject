#include "Pause.h"
#include <iostream>
#include "Mainmenustate.h"
Pause::Pause(sf::RenderWindow* window,std::stack<state*>* states,bool* q):state(window,states),gamestatequit(q)
{
	initialisebuttons();
}

void Pause::initialisebuttons()
{
	buttons["Continue"]=new Option("Continue",sf::Vector2f(window->getSize().x/2.0f-200.0,window->getSize().y/2.0f-100.0f),sf::Vector2f(200,100));
	buttons["Exit"]=new Option("Exit",sf::Vector2f(50,200),sf::Vector2f(100,100));
}

void Pause::update(float dt)
{
	
	this->Mouseposupdate();
	for(auto& a:buttons)
	{
		a.second->update(Mousepos);
	}
	if(buttons["Continue"]->buttonpressed())
	{
		
		this->endstate();
	}
	if(buttons["Exit"]->buttonpressed())
	{
		*gamestatequit=true;
		this->endstate();
		
		
	}
	
}
void Pause::render()
{
	
	for(auto& a:buttons)
	{
		a.second->render(window);
	}
}

#include "Levelup.h"
#include <iostream>
Levelup::Levelup(sf::RenderWindow* window,std::stack<state*>* states,bool& gonext):state(window,states),gonext(gonext)
{
	this->initButtons();
}

void Levelup::initButtons()
{
	buttons["NEXTLEVEL"]=new Option("Play Next",sf::Vector2f(window->getSize().x/2-100,window->getSize().y/2-100),sf::Vector2f(100,100));	
	buttons["REPLAY"]=new Option("Replay",sf::Vector2f(window->getSize().x/2-100,window->getSize().y/2),sf::Vector2f(100,100));
}

void Levelup::update(float dt)
{
	
	this->Mouseposupdate();
	for(auto& a:buttons)
	{
	
		a.second->update(Mousepos);
	}
	
	if(buttons["NEXTLEVEL"]->buttonpressed())
	{
		this->endstate();
		gonext=true;
	}
	if(buttons["REPLAY"]->buttonpressed())
	{
		this->endstate();
		gonext=false;
	}
	
}
void Levelup::render()
{
	for(auto& a:buttons)
	{
		
		a.second->render(window);
	}
}
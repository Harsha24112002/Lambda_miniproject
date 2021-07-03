#include "Levelup.h"
#include <iostream>
Levelup::Levelup(sf::RenderWindow* window,std::stack<state*>* states):state(window,states)
{
	this->initButtons();
	font.loadFromFile("HOMOARAK.TTF");
	text.setString("LEVEL CLEARED");
	text.setFont(font);
	
	text.setCharacterSize(60);
	text.setPosition(sf::Vector2f(500,200));
	//text.setStyle(sf::Text::Bold);
}

Levelup::~Levelup()
{
	for(auto& a:buttons)
	{
	delete a.second;
	}
}
void Levelup::initButtons()
{
	buttons["NEXTLEVEL"]=new Option("Continue",sf::Vector2f(window->getSize().x/2-100,window->getSize().y/2),sf::Vector2f(400,100));	
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
	}
}
void Levelup::render()
{
	for(auto& a:buttons)
	{
		
		a.second->render(window);
	}
	window->draw(text);
}
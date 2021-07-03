#include "Pause.h"
Pause::Pause(sf::RenderWindow* window,std::stack<state*>* states,bool* q):state(window,states),gamestatequit(q)
{
	initialisebuttons();
}
Pause::~Pause()
{
	for(auto& a:buttons)
	{
		delete a.second;
	}
	
}
void Pause::initialisebuttons()
{
	buttons["Continue"]=new Option("Continue",sf::Vector2f(XCOORDINATE,YCOORDINATE-100),sf::Vector2f(350,100));
	buttons["Exit"]=new Option("Exit",sf::Vector2f(XCOORDINATE,YCOORDINATE+100),sf::Vector2f(170,100));
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

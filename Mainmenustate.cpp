#include "Mainmenustate.h"
Mainmenustate::Mainmenustate(sf::RenderWindow* window,std::stack<state*>* states):state(window,states)
{
	this->initialisebuttons();
}

Mainmenustate::~Mainmenustate()
{
	for(auto& a:buttons)
	{
		delete a.second;
	}	
}

void Mainmenustate::initialisebuttons()
{
	buttons["GAME"]=new Option("Single",sf::Vector2f(XCOORDINATE,YCOORDINATE-200),sf::Vector2f BUTTONSIZE);
	buttons["DUO"]=new Option("Dual",sf::Vector2f(XCOORDINATE,YCOORDINATE),sf::Vector2f BUTTONSIZE);
	buttons["Exit"]=new Option("Exit",sf::Vector2f(XCOORDINATE,YCOORDINATE+200),sf::Vector2f BUTTONSIZE);
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

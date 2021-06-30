#include "Game.h"
#include <iostream>
Game::Game()
{	
	window=new sf::RenderWindow(sf::VideoMode::getDesktopMode(),"Space Invader");
	window->setFramerateLimit(60);
	window->setVerticalSyncEnabled(false);
	cursor.loadFromSystem(sf::Cursor::Hand);
	window->setMouseCursor(cursor);
	states.push(new Mainmenustate(window,&this->states));
	dt=0.0;
}

void Game::update()
{
	if(!this->states.empty())  
	{
		this->states.top()->update(dt); 
	while(!this->states.empty()&&this->states.top()->getquit())
	{
		delete states.top();
		states.pop();
	}
	
	
	}
	else endgame();
}
void Game::render()
{
	if(!this->states.empty())
	states.top()->render();
}
void Game::run()
{
	dt=clock.restart().asSeconds();
	while(window->isOpen())
	{
	sf::Event e;
	while(window->pollEvent(e))
	{
		if(e.type==sf::Event::Closed)
		{
			window->close();
		}
	}	
	update();
	render();
	
	window->display();
	window->clear();
	}
}
int main()
{
	Game game;
	game.run();
}
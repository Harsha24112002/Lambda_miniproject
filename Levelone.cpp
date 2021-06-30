#include "Levelone.h"
#include <iostream>

Levelone::Levelone(sf::Texture* Texture,std::list<Level*>* levels,std::vector<Enemy*>* enemies):Level(Texture,levels,enemies)
{
}

void Levelone::start()
{
	for(unsigned i=0;i<1;i++)
	{
		
		//enemies->push_back(new Enemy(Texture,sf::Vector2f(200+200*i,100)));
	
		enemies->push_back(new Enemy(Texture,sf::Vector2f(220+200*i,200)));
	}
	
}
/*void levelone::render(sf::RenderWindow* window)
{
	for(auto& a:*enemies)
	{
		std::cout<<"K"<<std::endl;
		a->render(window);
	}
}*/
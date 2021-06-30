#include "Leveltwo.h"
Leveltwo::Leveltwo(sf::Texture* Texture,std::list<Level*>* levels,std::vector<Enemy*>* enemies):Level(Texture,levels,enemies)
{
	
}

void Leveltwo::start()
{
	
		enemies->push_back(new Enemy(Texture,sf::Vector2f(100,50)));
		enemies->push_back(new Enemy(Texture,sf::Vector2f(300,50)));
		enemies->push_back(new Enemy(Texture,sf::Vector2f(500,50)));
		enemies->push_back(new Enemy(Texture,sf::Vector2f(700,50)));
		enemies->push_back(new Enemy(Texture,sf::Vector2f(900,50)));

		enemies->push_back(new Enemy(Texture,sf::Vector2f(200,200)));
		enemies->push_back(new Enemy(Texture,sf::Vector2f(400,200)));
		enemies->push_back(new Enemy(Texture,sf::Vector2f(600,200)));
		enemies->push_back(new Enemy(Texture,sf::Vector2f(800,200)));

		enemies->push_back(new Enemy(Texture,sf::Vector2f(300,300)));
		enemies->push_back(new Enemy(Texture,sf::Vector2f(500,300)));
		enemies->push_back(new Enemy(Texture,sf::Vector2f(700,300)));	

		enemies->push_back(new Enemy(Texture,sf::Vector2f(400,400)));
		enemies->push_back(new Enemy(Texture,sf::Vector2f(600,400)));	

		
	
}

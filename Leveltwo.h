#ifndef LEVELTWO_H
#define LEVELTWO_H
#include "Level.h"

class Leveltwo: public Level
{
	private:
	public:
	Leveltwo(sf::Texture* Texture,std::list<Level*>* levels,std::vector<Enemy*>* enemies);
	void start();
	//void render(sf::RenderWindow* window);
};
	



#endif
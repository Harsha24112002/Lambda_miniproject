#ifndef LEVELONE_H
#define LEVELONE_H
#include "Level.h"

class Levelone: public Level
{
	private:

	public:
	Levelone(sf::Texture* Texture,std::list<Level*>* levels,std::vector<Enemy*>* enemies);
	void start();
		//void render(sf::RenderWindow* window);
};

#endif
#ifndef LEVEL_H
#define LEVEL_H
#include "State.h"
#include "Enemy.h"
#include <list>
class Level
{
	protected:
	
	sf::Texture* Texture;
	std::list<Level*>* levels;
	std::vector<Enemy*>* enemies;
	
	bool complete;

	public:
	Level(sf::Texture* Texture,std::list<Level*>* levels,std::vector<Enemy*>* enemies);
	void update();
	bool getlevel();
	virtual void start()=0;

	//virtual void render(sf::RenderWindow* window)=0;
};


#endif
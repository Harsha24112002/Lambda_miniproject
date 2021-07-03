#ifndef LEVEL_H
#define LEVEL_H
#include "State.h"
#include "Enemy.h"
#include <fstream>
#include <list>
class Level
{
	protected:
	
	sf::Texture* Texture;
	std::list<Level*>* levels;
	std::vector<Enemy*>* enemies;
	sf::Texture* enembultex;
	std::string filename;
	bool complete;

	public:
	Level(sf::Texture* Texture,sf::Texture*,std::string s,std::vector<Enemy*>* enemies);
	virtual ~Level();
	void start();
	void update();
	bool getlevel();

};


#endif
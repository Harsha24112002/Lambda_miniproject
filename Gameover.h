#ifndef GAMEOVER_H
#define GAMEOVER_H
#include "Option.h"
#include "State.h"

class Gameover: public state
{
	private:
	std::map<std::string,Option*> buttons;
	void initButtons();
	bool* gamestatequit;
	public:
	Gameover(sf::RenderWindow* window,std::stack<state*>* states,bool*);
	void update(float dt);
	void render();

};

#endif
#ifndef LEVELUP_H
#define LEVELUP_H
#include "State.h"
#include "Option.h"

class Levelup : public state
{
	private:
	std::map<std::string,Option*> buttons;	
	void initButtons();
	bool& gonext;

	public:
	Levelup(sf::RenderWindow* window,std::stack<state*>* states,bool& gonext);
	~Levelup(){};
	void update(float dt);
	void render();

};

#endif
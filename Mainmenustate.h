#ifndef MAINMENUSTATE_H
#define MAINMENUSTATE_H
#include "State.h"
#include "Option.h"
#include "Singleplayer.h"
#include "Dualplayer.h"
#include <map>
class Mainmenustate: public state
{
	private:
	std::map<std::string,Option*> buttons;
	void initialisebuttons();


	public:
	Mainmenustate(sf::RenderWindow* window,std::stack<state*>* states);
	~Mainmenustate();
	
	void update(float dt);
	void render();
};

#endif

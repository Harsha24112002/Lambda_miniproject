#ifndef PAUSE_H
#define PAUSE_H
#include "State.h"
#include "Mainmenustate.h"
#include "Option.h"
class Pause : public state
{
private:
	std::map<std::string,Option*> buttons;
	void initialisebuttons();
	bool* gamestatequit;
public:
	Pause(sf::RenderWindow* window,std::stack<state*>*states,bool* q);
	~Pause();

	void update(float dt);
	void render();
};
#endif


#ifndef LEVELUP_H
#define LEVELUP_H
#include "State.h"
#include "Option.h"

class Levelup : public state
{
	private:
	std::map<std::string,Option*> buttons;	
	void initButtons();
	sf::Font font;
	sf::Text text1;
	sf::Text text2;
	sf::Text text;
	unsigned totalscore;
	unsigned levelscore;
	//bool& gonext;

	public:
	Levelup(sf::RenderWindow* window,std::stack<state*>* states);
	
	virtual ~Levelup();
	void update(float dt);
	void render();

};

#endif
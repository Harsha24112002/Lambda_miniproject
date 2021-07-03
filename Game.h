#include<SFML/Graphics.hpp>
#include"State.h"
#include<stack>
#include "Option.h"
#include "Mainmenustate.h"
class Game
{
	private:
	sf::RenderWindow* window;
	std::stack<state*> states;
	sf::Clock clock;
	sf::Cursor cursor;
	float dt;
	public:
	Game();
	~Game();
	void update();
	void render();
	void endgame(){this->window->close();}
	void run();
};
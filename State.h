#ifndef STATE_H
#define STATE_H
#include<SFML/Graphics.hpp>
#include <stack>
class state
{
	private:
	
	protected:
	std::map<std::string,sf::Texture*> textures;
	sf::Vector2i Mousepos;
	sf::RenderWindow* window;
	void Mouseposupdate();
	std::stack<state*>* states; 
	void endstate(){this->quit=true;}
	bool quit;
		
	public:
	state(sf::RenderWindow* window,std::stack<state*>* states);
	~state();
	bool getquit(){return this->quit;}
	virtual void update(float dt)=0;
	virtual void render()=0;
};
#endif
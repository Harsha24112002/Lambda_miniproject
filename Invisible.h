#ifndef INVISIBLE_H
#define INVISIBLE_H
#include "Powerup.h"

class Invisible : public Powerup
{
	public: 
	Invisible(sf::Texture* tex,sf::Vector2f pos);
	void update(float dt);
	void render(sf::RenderWindow* window);

};


#endif
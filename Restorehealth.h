#ifndef RESTOREHEALTH_H
#define RESTOREHEALTH_H

#include "Powerup.h"

class Medicine: public Powerup
{
	public:
	Medicine(sf::Texture* tex,sf::Vector2f pos);
	void update(float dt);
	void render(sf::RenderWindow* window);
};

#endif
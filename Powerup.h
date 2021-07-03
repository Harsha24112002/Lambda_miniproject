#ifndef POWERUP_H
#define POWERUP_H

#include "SFML/Graphics.hpp"
#include "Collider.h"
#define POWERUPVEL 200.0
class Powerup
{
	protected:
	sf::Sprite sprite;

	public:
	Powerup(sf::Texture* tex,sf::Vector2f pos);
	Collider getcollider(){return Collider(sprite);}
	sf::Vector2f getpos(){return sprite.getPosition();}
	virtual void update(float dt)=0;
	virtual void render(sf::RenderWindow* window)=0;
};


#endif
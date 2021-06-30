#ifndef COLLIDER_H
#define COLLIDER_H

#include <SFML/Graphics.hpp>
#include "Animation.h"
class Collider
{
	private:
	sf::Sprite& sprite;


	public:
	Collider(sf::Sprite& sprite);
	sf::FloatRect getglobalbounds(){return sprite.getGlobalBounds();}
	sf::Vector2f getpos(){return sprite.getPosition();}
	bool checkcollison(Collider enemy);
};


#endif
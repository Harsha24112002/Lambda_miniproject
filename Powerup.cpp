#include "Powerup.h"

Powerup::Powerup(sf::Texture* tex,sf::Vector2f pos)
{
	sprite.setTexture(*tex);
	sprite.setPosition(pos);
}
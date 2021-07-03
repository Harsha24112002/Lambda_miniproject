#include "Invisible.h"

Invisible::Invisible(sf::Texture* tex,sf::Vector2f pos): Powerup(tex,pos)
{
      sprite.setScale(0.3,0.3);
}

void Invisible::update(float dt)
{
	sf::Vector2f movement={0.0,0.0};
	movement.y=POWERUPVEL*dt;
	sprite.move(movement);
}

void Invisible::render(sf::RenderWindow* window)
{
	window->draw(sprite);
}
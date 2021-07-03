#include "Shield.h"

Shield::Shield(sf::Texture* tex,sf::Vector2f pos):Powerup(tex,pos)
{
	sprite.setScale(0.25,0.25);
	sprite.setColor(sf::Color::Cyan);
}
void Shield::update(float dt)
{
	sf::Vector2f movement={0.0,0.0};
	movement.y=POWERUPVEL*dt;
	sprite.move(movement);
}

void Shield::render(sf::RenderWindow* window)
{
	window->draw(sprite);
}
#include "Restorehealth.h"

Medicine::Medicine(sf::Texture* tex,sf::Vector2f pos):Powerup(tex,pos)
{
 sprite.setScale(0.2,0.2);
 sprite.setColor(sf::Color((sf::Color::White.toInteger())));
}

void Medicine::update(float dt)
{
	sf::Vector2f movement={0.0,0.0};
	movement.y=POWERUPVEL*dt;
	sprite.move(movement);
}

void Medicine::render(sf::RenderWindow* window)
{
	window->draw(sprite);
}


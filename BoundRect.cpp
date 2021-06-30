#include "Boundrect.h"

BoundRect::BoundRect(sf::Sprite& sprite,sf::Vector2f offset,sf::Vector2f size):sprite(sprite)
{
	bound.setSize(size);
	bound.setPosition(size);
} 

void BoundRect::update()
{

}


void BoundRect::render(sf::RenderWindow* window)
{
	
}
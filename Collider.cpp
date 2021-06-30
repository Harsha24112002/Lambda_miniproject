#include "Collider.h"

Collider::Collider(sf::Sprite& sprite):sprite(sprite)
{

}

bool Collider::checkcollison(Collider body)
{
	if(sprite.getGlobalBounds().intersects(body.getglobalbounds()))
	{
	
		return true;
	}
	return false;
}

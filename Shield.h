#ifndef SHIELD_H
#define SHIELD_H
#include <SFML/Graphics.hpp>
#include "Collider.h"
#include "Powerup.h"
class Shield : public Powerup
{

	public:
	Shield(sf::Texture* texture,sf::Vector2f pos);
	//sf::Vector2f getpos(){return shield.getPosition();}
	//Collider getcolldier(){return Collider(shield);}
	void update(float dt);
	void render(sf::RenderWindow* window);

};
#endif
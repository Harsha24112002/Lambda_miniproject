#ifndef BULLET_H
#define BULLET_H
#include<SFML/Graphics.hpp>
#include "Collider.h"
class Bullet
{
	private:
	sf::Sprite bullet;
	float direction;
	float speed;
	public:
	Bullet(sf::Texture* t,sf::Vector2f pos,float direction,sf::Color color,float speed);
	~Bullet();
	
	sf::Vector2f getpos(){return bullet.getPosition();}
	void update(float dt);
	void render(sf::RenderWindow* window);
	Collider getcollider(){return Collider(bullet);}
};
#endif
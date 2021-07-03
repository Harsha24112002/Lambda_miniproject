#include "Bullet.h"
#include <iostream>
Bullet::Bullet(sf::Texture* t,sf::Vector2f pos,float direction,sf::Color color,float speed)
{
	bullet.setTexture(*t);
	bullet.setPosition(pos);
	bullet.setColor(color);
	this->speed=speed;
	this->direction=direction;
}
Bullet::~Bullet()
{

}

void Bullet::update(float dt)
{
	bullet.move(0.0f,-direction*this->speed*dt);
}
void Bullet::render(sf::RenderWindow* window)
{
	window->draw(bullet);
}
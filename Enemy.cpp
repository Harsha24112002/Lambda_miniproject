#include "Enemy.h"

#include <iostream>
 Enemy::Enemy(sf::Texture* t,sf::Vector2f pos,sf::Texture* exptex)
 {
	 enemy.setTexture(*t);
	 enemy.setPosition(pos);
	 enemy.setScale(0.2,0.2);
	 enemy.setOrigin(sf::Vector2f(enemy.getGlobalBounds().width/2.0f,enemy.getGlobalBounds().height/2.0f));
	 enemy.setColor(sf::Color::Yellow);
	 this->position = pos;
	 
	 acceleration=EACC;	
	velocity.x=EVEL;
	velocity.y=0.0f;
	direction=1.0f;
	distance=0.0f;
	this->collided=false;
	this->expcomp=false;	
	a=new Animation(exptex,sf::Vector2f(enemy.getPosition().x+15,enemy.getPosition().y-30),0.3);
	
 }
 Enemy::~Enemy()
 {
 }
 void Enemy::update(float dt)
 {	
	 if(!collided)
	{
	 distance+=velocity.x*dt*direction;
	 if(distance>100.0f)
	 {
		 distance=0.0f;
		 direction=-1.0f;
	 }
	if(distance<-100.0f)
	{
		distance=0.0f;
		direction=1.0f;
	}
	enemy.move(velocity*dt*direction);
	}
	if(collided)
	{
		
		a->update(dt);
	}

 }
 void Enemy::render(sf::RenderWindow* window)
 {
	 if(!collided)
	 {
	 window->draw(enemy);
	 }
	 if(collided)
	 {
		 a->render(window);
	 }
 }
 void Enemy::onCollison()
 {
	collided=true;
 }
#ifndef ENEMY_H
#define ENEMY_H
#include<SFML/Graphics.hpp>
#include "Collider.h"
#include "Bullet.h"
 class Enemy
 {
	private:
	sf::Sprite enemy;
	sf::Vector2f position;
	float acceleration;
	sf::Vector2f velocity;
	sf::Vector2f maxvelocity;
	float direction;
	float distance;
	Animation* a=nullptr;
	bool collided;
	bool expcomp=false;
	public:
	Enemy(sf::Texture* t,sf::Vector2f setpos);
	~Enemy();
	void update(float dt);
	void move(float dt);
	void render(sf::RenderWindow* window);
	sf::Vector2f getpos(){return enemy.getPosition();}
	Collider getcollider(){return Collider(enemy);}
	void onCollison();
	bool iscollided(){return collided;}
	bool animationcomplete(){return a->explosion();}
 };


#endif
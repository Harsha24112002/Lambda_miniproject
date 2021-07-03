#ifndef ENEMY_H
#define ENEMY_H
#include<SFML/Graphics.hpp>
#include "Collider.h"
#include "Bullet.h"
#define EVEL 100
#define EACC 200
 class Enemy
 {
	private:
	sf::Sprite enemy;
	sf::Vector2f position;
	float acceleration;
	sf::Vector2f velocity;
	
	float direction;
	float distance;
	Animation* a;
	bool collided;
	bool expcomp;
	public:
	Enemy(sf::Texture* t,sf::Vector2f setpos,sf::Texture* exptex);
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
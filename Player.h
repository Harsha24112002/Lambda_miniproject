#ifndef PLAYER_H
#define PLAYER_H
#define TimebetweenBullets 50.0
#include <SFML/Graphics.hpp>
#include"Bullet.h"
#include "Enemy.h"
#include <vector>
#include <string>
class Player
{
	private:
	sf::Sprite body;
	float velocity;
	sf::Vector2f movement;
	unsigned score;	
	std::vector<Bullet*> bullets;
	sf::Font font;
	sf::Text text;
	sf::Texture bullettex;
	float Bulletreltime;
	unsigned count=0;
	std::string s;

	public:
	Player(sf::Texture* t,sf::Color color);
	~Player();
	void move(sf::Vector2f direction,float dt);
	void update(float dt);
	void render(sf::RenderWindow* window);
	void increasescore();
	void textformat(std::string a,sf::Vector2f pos);
	bool checkhitenemy(Enemy* enemy);
	bool checkhitbullet(Bullet* bullet);
	void setpos(sf::Vector2f pos){body.setPosition(pos);}
	void updatebullets(float dt);
	void createbullet();
	sf::Vector2f getpos(){return body.getPosition();}
	Collider getcollider(){return Collider(body);}
	
};


#endif
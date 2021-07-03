#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>
#include"Bullet.h"
#include "Enemy.h"
#include <vector>
#include <string>
#define SHIELDONTIME 5.0
#define TIMEBETWEENBULLETS 1.45
#define SHIELDSIZE 70.0
#define PVEL 500.0
#define BULLETSPEED 360.0
enum Powerups {SHIELD=0,INVISIBILTY,MEDICINE};
class Player
{
	private:
	sf::Sprite body;
	float velocity;
	sf::Vector2f movement;
	unsigned score;	
	std::vector<Bullet*> bullets;
	sf::CircleShape* shield;
	sf::Vector2f pos;
	sf::Texture* bullettex;
	float Bulletreltime;
	float shieldtime;
	unsigned kill;
	sf::Color color;
	Powerups type;
	bool invisible;
	public:
	Player(sf::Texture* t,sf::Color color,sf::Texture* bullettex,sf::Vector2f pos);
	~Player();

	void incrementkill(){kill--;}
	unsigned getkill(){return kill;}
	void move(sf::Vector2f direction, float dt);
	void update(float dt);
	void render(sf::RenderWindow* window);
	void increasescore();
	sf::Color getcolor(){return body.getColor();}
	unsigned getscore(){return score;}
	bool checkhitenemy(Enemy* enemy);
	bool checkhitbullet(Bullet* bullet);
	bool hasshield(){return shield;}
	void equip(Powerups type);
	void getheal();
	void reset();
	sf::Vector2f getpos(){return body.getPosition();}	
	void setpos(sf::Vector2f pos){body.setPosition(pos);}
	void updatebullets(float dt);
	void createbullet();
	bool isinvisible(){return invisible;}
	Collider getcollider(){return Collider(body);}
	
};


#endif
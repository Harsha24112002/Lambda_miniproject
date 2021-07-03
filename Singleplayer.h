#ifndef SINGLEPLAYER_H
#define SINGLEPLAYER_H
#define POWERUPTIME 15.0
#define PLAYERPOS (window->getSize().x/2.0f,window->getSize().y-100)
#include "State.h"
#include "Player.h"
#include "Enemy.h"
#include "Restorehealth.h"
#include "Playerattributes.h"
#include <list>
#include "Shield.h"
#include "Pause.h"
#include "Level.h"
#include "Levelup.h"
#include "Invisible.h"
#include "Gameover.h"
class Singleplayer : public state
{
	public:
	Singleplayer(sf::RenderWindow* window,std::stack<state*>* states);
	~Singleplayer();
	void updateinput(float dt);
	void update(float dt);
	void updatecollison();
	void updatebullets();
	void checkplayersafety();
	void levelupdates();
	void intilevels();
	void startlevel();
	void render();


	protected:
	Player* player;
	Attributes* attributes;
	std::vector<Enemy*> enemies;
	sf::Vector2f direction;
	Powerup* powerup;
	Powerups type;
	Bullet* enemybullet;
	unsigned score;
	float ebt;
	sf::RectangleShape ammo1;
	std::list<Level*> levels;
	sf::RectangleShape background;
	float poweruptime;
	void CreateBullet(float dt);
	void CreateEnemyBullet(sf::Vector2f pos);
	int getnearestenemy();
	void Deletepowerup();
	void Initbackground();
	void checkcatchedpowerup();
	void Checkcollisonwithbullets();
	void Createpowerup();
	bool CheckPlayerBounds();
	void Createplayer();
};

#endif
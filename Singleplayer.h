#ifndef SINGLEPLAYER_H
#define SINGLEPLAYER_H
#include "State.h"
#include "Player.h"
#include "Enemy.h"
#include <list>
#include "Pause.h"
#include "Level.h"
#include "Levelone.h"
#include "Levelup.h"
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
	std::vector<Enemy*> enemies;
	sf::Vector2f direction;
	unsigned playerhit=0;
	//std::vector<Bullet*> bullets;
	Bullet* enemybullet;
	sf::RectangleShape ammo1;
	std::list<Level*> levels;
	bool gonext;

	unsigned activebulletid=0;	
	unsigned count=0;
	float totaltime=0;
	void CreateBullet(float dt);
	void CreateEnemyBullet(sf::Vector2f pos);
	int getnearestenemy();
	void Checkcollisonwithbullets();
	bool CheckPlayerBounds();
};

#endif
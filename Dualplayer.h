#ifndef DUALPLAYER_H
#define DUALPLAYER_H
#include "State.h"
#include "Player.h"
#include "Enemy.h"
#include <list>
#include "Pause.h"
#include "Level.h"
#include "Levelone.h"
#include "Leveltwo.h"
#include "Levelup.h"
class Dualplayer : public state
{
	public:
	Dualplayer(sf::RenderWindow* window,std::stack<state*>* states);
	~Dualplayer();

	void update(float dt);
	void render();


	protected:
	Player* player1;
	Player* player2;
	std::vector<Enemy*> enemies;
	sf::Vector2f direction;
	sf::Vector2f direction2;
	//std::vector<Bullet*> bullets1;
	//std::vector<Bullet*> bullets2;
	Bullet* enemybullet1;
	Bullet* enemybullet2;
	sf::RectangleShape ammo1;
	std::list<Level*> levels;
	bool gonext;
	unsigned activebulletid=0;	
	unsigned count;
	float totaltime;
	float totaltime2;
	float revivetime;
	void updateinput(float dt);
	void updateinputtwo(float dt);
	
	void updatecollison();
	void updatebullets();
	void checkplayersafety(Bullet* enemybullet);
	void levelupdates();
	void intilevels();
	void startlevel();
	void CreateBullet1(float dt);
	void CreateBullet2(float dt);
	void Rebirth(float dt);
	void CreateEnemyBullet1(sf::Vector2f pos);
	void CreateEnemyBullet2(sf::Vector2f pos);
	int getnearestenemy(Player*);
	void Checkcollisonwithbullets(Player* player);
	bool CheckPlayerBounds(Player*);
	void CreatePlayer1();
	void CreatePlayer2();
	void initvariables();
};



#endif
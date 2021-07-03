#ifndef DUALPLAYER_H
#define DUALPLAYER_H
#define SHIELDLIVETIME 150.0f
#include "State.h"
#include "Player.h"
#include "Enemy.h"
#include "Shield.h"
#include "Invisible.h"
#include "Playerattributes.h"
#include <list>
#include "Pause.h"
#include "Level.h"
#include "Singleplayer.h"
#include "Levelup.h"
#define PLAYER1POS (window->getSize().x/2.0f-100,window->getSize().y-100)
#define PLAYER2POS (window->getSize().x/2.0f+100,window->getSize().y-100)
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

	Attributes* attribute1;
	Attributes* attribute2;
	std::vector<Enemy*> enemies;
	sf::Vector2f direction;
	sf::Vector2f direction2;
	Powerups type;
	unsigned count=0;
	sf::RectangleShape background;
	float ebt1;
	float ebt2;
	unsigned player1score;
	unsigned player2score;
	Powerup* powerup;
	Bullet* enemybullet1;
	Bullet* enemybullet2;
	sf::RectangleShape ammo1;
	std::list<Level*> levels;
	bool gonext;
	float revivetime;
	float poweruptime;
	void updateinput(float dt);
	void updateinputtwo(float dt);
	void checkcatchedpowerup();
	void updatecollison();
	void updatebullets();
	void checkplayersafety();
	void levelupdates();
	void intilevels();
	void startlevel();
	void Initbackground();
	void Deletepowerup();
	void CreateBullet1(float dt);
	void CreateBullet2(float dt);
	void Rebirth(float dt);
	void CreateEnemyBullet1(sf::Vector2f pos);
	void CreateEnemyBullet2(sf::Vector2f pos);
	int getnearestenemy(Player*);
	void CreatePowerup();
	void Checkcollisonwithbullets(Player* player);
	bool CheckPlayerBounds(Player*);
	void CreatePlayer1();
	void CreatePlayer2();
	void initvariables();
};



#endif
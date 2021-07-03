#include "Dualplayer.h"
#include<iostream>
#include<stdexcept>

Dualplayer::Dualplayer(sf::RenderWindow* window,std::stack<state*>* states):state(window,states)
{

	
	player1=nullptr;
	player2=nullptr;
	this->CreatePlayer1();
	this->CreatePlayer2();
	this->intilevels();
	this->Initbackground();
	this->initvariables();

	
}
Dualplayer::~Dualplayer()
{
	
	delete attribute1;
	delete attribute2;
	delete powerup;
	
}

void Dualplayer::initvariables()
{
	powerup=nullptr;
	gonext=true;
	player1score=0;
	player2score=0;
	direction={0.0f,0.0f};
	direction2={0.0f,0.0f};
	enemybullet1=nullptr;
	enemybullet2=nullptr;
	revivetime=0.0f;
	ebt1=0.0f;
	ebt2=0.0f;
	poweruptime=0.0f;
	attribute1 = new Attributes(player1,"PLAYER 1 : ",100.0);
	attribute2 = new Attributes(player2,"PLAYER 2 : ",300.0);

}
void Dualplayer::Initbackground()
{
	background.setTexture(textures["BACKGROUND"]);
	background.setSize(sf::Vector2f((float)window->getSize().x,(float)window->getSize().y));
	background.setPosition((float)window->getPosition().x,(float)window->getPosition().y);
	background.setFillColor(sf::Color(sf::Color::White.toInteger()));
}

void Dualplayer::CreatePlayer1()
{
	if(!player1)
	player1 = new Player(textures["PLAYER"],sf::Color::Cyan,textures["BULLET"],sf::Vector2f PLAYER1POS);
}
void Dualplayer::CreatePlayer2()
{
	if(!player2)
	player2=new Player(textures["PLAYER"],sf::Color(255,131,250,255),textures["BULLET"],sf::Vector2f PLAYER2POS);
}
void Dualplayer::intilevels()
{
	levels.push_back(new Level(textures["ENEMY"],textures["EXPLOSION"],"levelonepositions.txt",&enemies));
	levels.push_back(new Level(textures["ENEMY"],textures["EXPLOSION"],"leveltwopositions.txt",&enemies));
	startlevel();
}
void Dualplayer::startlevel()
{
	if(levels.front())
	{
		levels.front()->start();
	}
}
void Dualplayer::CreateBullet1(float dt)
{	
	if(player1)
	{
		player1->createbullet();
	}
}
void Dualplayer::CreateBullet2(float dt)
{	
	if(player2)
	{
	
	player2->createbullet();
				
	}
}

void Dualplayer::CreateEnemyBullet1(sf::Vector2f pos)
{
	if(!enemybullet1 && !player1->isinvisible() &&ebt1>TIMEBETWEENBULLETS)
	{
	enemybullet1=(new Bullet(textures["ENEMYBULLET"],pos,-1.0f,sf::Color::Green,1.5*BULLETSPEED));
	ebt1=0;
	}
}

void Dualplayer::CreateEnemyBullet2(sf::Vector2f pos)
{
	if(!enemybullet2 && !player2->isinvisible() && ebt2>TIMEBETWEENBULLETS)
	{
	enemybullet2=new Bullet(textures["ENEMYBULLET"],pos,-1.0f,sf::Color::Green,1.5*BULLETSPEED);
	ebt2=0;
	}
}
bool Dualplayer::CheckPlayerBounds(Player* player1)
{

	if(player1->getpos().x>=0 && player1->getpos().x<=window->getSize().x)
	{
		return true;
	}
	else if(player1->getpos().x<0)
	{
		player1->setpos(sf::Vector2f(20,player1->getpos().y));
	}
	else if(player1->getpos().x>window->getSize().x)
	{
		player1->setpos(sf::Vector2f( window->getSize().x-20,player1->getpos().y));
	
	}
	return false;
	
}

void Dualplayer::updateinput(float dt)
{
	direction={0.0f,0.0f};
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		direction={1.0f,0.0f};
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		direction={-1.0f,0.0f};
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		CreateBullet1(dt);
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		states->push(new Pause(window,states,&quit));
	}
	

	if(player1)
	{
		if(CheckPlayerBounds(player1))
		{
			player1->move(direction,dt);
		}
	}
	
	
}
void Dualplayer::updateinputtwo(float dt)
{
	direction2={0.0f,0.0f};
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		direction2={1.0f,0.0f};
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		direction2={-1.0f,0.0f};
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
	{
		CreateBullet2(dt);
	}
	if(player2)
	{
		if(CheckPlayerBounds(player2))
		{
			player2->move(direction2,dt);
		}
	}
}
void Dualplayer::updatecollison()
{		
	unsigned index=0;
		
	for(auto i=enemies.begin();i!=enemies.end() && index<enemies.size();i++,index++)
	{

		if(player1)
		{	
		if(player1->checkhitenemy(enemies[index]))
		{
			player1->increasescore();
			enemies[index]->onCollison();
			break;
		}

		}
	}
	index=0;
	for(auto i=enemies.begin();i!=enemies.end() && index<enemies.size();i++,index++)
	{
		if(player2)
		{	
		if(player2->checkhitenemy(enemies[index]))
		{
			player2->increasescore();
			enemies[index]->onCollison();
			break;
		}
		
		}
	}
	int k=0;
	for(auto it=enemies.begin();it!=enemies.end()&& k<enemies.size();it++,k++)	
	{
	
		if(enemies[k]->iscollided())
		{
		
			if(enemies[k]->animationcomplete())
			{
				enemies[k]->~Enemy();
				enemies.erase(it);
				k--;
			
				
			}
		}
	}
}
void Dualplayer::updatebullets()
{
	if(enemies.size()==1 && player1 && player2)
	{
		if(!enemybullet1 && !enemybullet2)
		CreateEnemyBullet1(enemies[0]->getpos());
	}
	else{
	if(!enemybullet1)
	{
		if(getnearestenemy(player1)>=0)
		{
		CreateEnemyBullet1(enemies[getnearestenemy(player1)]->getpos());
		}
	}
	 if(!enemybullet2)
	{
		if(getnearestenemy(player2)>=0)
		{
			CreateEnemyBullet2(enemies[getnearestenemy(player2)]->getpos());
		}
	}
	}
	if(enemybullet1)
	{
	if(enemybullet1->getpos().y>window->getSize().y)
	{
		delete enemybullet1;
		enemybullet1=nullptr;
		
	}
	}
	if(enemybullet2)
	{
	if(enemybullet2->getpos().y>window->getSize().y)
	{
		delete enemybullet2;
		enemybullet2=nullptr;
		
	}		
	}
	
}
void Dualplayer::CreatePowerup()
{
	int a= rand()%3;
	
	switch(a)
	{
		case 0: 
		{
			if(poweruptime>POWERUPTIME)
			{
			poweruptime=0;
			float xpos=rand()%(window->getSize().x-100);
			powerup=new Shield(textures["SHIELD"],sf::Vector2f(xpos,-20));
			type=SHIELD;
			}
			
			break;
		}
		case 1:
		{
			if(poweruptime>POWERUPTIME)
			{
			poweruptime=0;
			float xpos=rand()%(window->getSize().x-100);
			powerup=new Invisible(textures["INVISIBLE"],sf::Vector2f(xpos,-20));
			type=INVISIBILTY;
			}
			
			break;
		}
		case 2:
		{
			if(poweruptime>POWERUPTIME)
			{
				poweruptime=0;
				if(!powerup)
				{
				float xpos=rand()%(window->getSize().x-100);
				powerup=new Medicine(textures["MEDICINE"],sf::Vector2f(xpos,-20));	
				type=MEDICINE;
				}
				
				break;
			}
		}
	}
	
	
}
void Dualplayer::checkcatchedpowerup()
{

	if(player1 && powerup)
	{
	if(powerup->getcollider().checkcollison(player1->getcollider()))
	{
		if(powerup)
		{
		delete powerup;
		powerup=nullptr;
		player1->equip(type);
		}
	}
	}
	if(player2 && powerup)
	{
	if(powerup->getcollider().checkcollison(player2->getcollider()))
	{
		if(powerup)
		{
			delete powerup;
			powerup=nullptr;
			player2->equip(type);
		}
	}
	}
	
}
void Dualplayer::levelupdates()
{
	if(levels.empty())
	{
		this->endstate();
	}
	else 
	{
		if(levels.front()->getlevel())
		{
			if(enemybullet1)
			{
			delete enemybullet1;
			enemybullet1=nullptr;
			}
			if(enemybullet2)
			{
			delete enemybullet2;
			enemybullet2=nullptr;
			}
			delete levels.front();
			levels.pop_front();
			player1score+=player1->getscore();
			player2score+=player2->getscore();
			player1->reset();
			player2->reset();
			delete powerup;
			powerup=nullptr;	
			if(levels.empty())
			{
				this->endstate();
				states->push(new Levelup(window,states));			
			}
			else
			{
				states->push(new Levelup(window,states));			
				if(!player1)
				{
					CreatePlayer1();
				}
				if(!player2)
				{
					CreatePlayer2();
				}
				this->startlevel();	
			}
		}
		
		else 
		{
			levels.front()->update();
			
		}
	}
}
void Dualplayer::Rebirth(float dt)
{
	if(player1 && player2)
	{
	revivetime=0;
	}
	revivetime+=dt;
	if(!player1)
	{
		if(revivetime>30)
		{
			CreatePlayer1();
		}
	}
	if(!player2)
	{
		if(revivetime>30)
		{
			CreatePlayer2();
		}
	}
} 
void Dualplayer::update(float dt)
{

	
	levelupdates();
	poweruptime+=dt;
	ebt1+=dt;
	ebt2+=dt;
	Rebirth(dt);
	updateinput(dt);
	updateinputtwo(dt);
	CreatePowerup();
	if(player1)
	{
	player1->update(dt);
	}
	if(player2)
	{
		player2->update(dt);
	}
	for(auto& a:enemies)
	{
		a->update(dt);
	}
	
	updatebullets();	
	if(enemybullet1)
	{
		enemybullet1->update(dt);
	}
	if(enemybullet2)
	{
		enemybullet2->update(dt);
	}
	if(powerup)
	{
		powerup->update(dt);
	}
	attribute1->update(dt);
	attribute2->update(dt);
	updatecollison();
	
	checkcatchedpowerup();
	
	Deletepowerup();
	
	checkplayersafety();
	
	Checkcollisonwithbullets(player1);
	Checkcollisonwithbullets(player2);
	
}
void Dualplayer::Checkcollisonwithbullets(Player* player)
{
	if(enemybullet1 && player)
	{
		if(player->checkhitbullet(enemybullet1))
		{
			delete enemybullet1;
			enemybullet1=nullptr;
		
		}
	}
	
	if(enemybullet2 &&player)
	{
		if(player->checkhitbullet(enemybullet2))
		{
			delete enemybullet2;
			enemybullet2=nullptr;
		
		}
	}
	
}
void Dualplayer::checkplayersafety()
{

	
	if(player1 && enemybullet1)
	{	
	if(enemybullet1->getcollider().checkcollison(player1->getcollider()))
	{
		if(!player1->hasshield())
		{
		player1->incrementkill();
		}
		delete enemybullet1;
		enemybullet1=nullptr;
	}
	}
	if(player2 && enemybullet1)
	{
	if(enemybullet1->getcollider().checkcollison(player2->getcollider()))
	{
		if(!player2->hasshield())
		{
		player2->incrementkill();
		}
		
		delete enemybullet1;
		enemybullet1 =nullptr;
		
	}
	}
	
	
	if(player1 && enemybullet2)
	{	
	if(enemybullet2->getcollider().checkcollison(player1->getcollider()))
	{
		if(!player1->hasshield())
		{
			player1->incrementkill();
		}
		delete enemybullet2;
		enemybullet2=nullptr;
	}
	}
	if(player2 && enemybullet2)
	{
	if(enemybullet2->getcollider().checkcollison(player2->getcollider()))
	{
		if(!player2->hasshield())
		{
			player2->incrementkill();
		}
		delete enemybullet2;
		enemybullet2 =nullptr;
		
	}
	
	}
	if(player1 && player1->getkill()==0)
	{
		delete player1;
		player1=nullptr;
	}
	if(player2 && player2->getkill()==0)
	{
		delete player2;
		player2=nullptr;
	}
	if(!player1 && !player2)
	{
		states->push(new Gameover(window,states,&quit));
	}
}

int Dualplayer::getnearestenemy(Player* player1)
{
	float min;
	if(enemies.size()>0 && player1)
	{
	min=INT64_MAX;
	int store=0;
	for(unsigned i=0;i<enemies.size();i++)
	{
		if(abs(enemies[i]->getpos().x-player1->getpos().x)<=min)
		{
			min=abs(enemies[i]->getpos().x-player1->getpos().x);
			store=i;
		}
	
	}
	
	return store;
	}
	return -1;
}
void Dualplayer::Deletepowerup()
{
	if(powerup)
	{
	if(powerup->getpos().y>window->getSize().y+100)
	{
		delete powerup;
		powerup=nullptr;
	}
	}
}	
void Dualplayer::render()
{
	
	window->draw(background);
	for(auto& a:enemies)
	{
		a->render(window);
	}
	
	if(player1)
	{
	
	player1->render(window);
	}
	if(player2)
	{
		player2->render(window);
	}
	attribute1->render(window);
	attribute2->render(window);
	if(enemybullet1)
	{
		enemybullet1->render(window);
	}
	if(enemybullet2)
	{
		enemybullet2->render(window);
	}
	if(powerup)
	{
		powerup->render(window);
	}
}
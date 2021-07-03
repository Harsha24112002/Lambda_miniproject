#include "Singleplayer.h"


#include <iostream>
Singleplayer::Singleplayer(sf::RenderWindow* window,std::stack<state*>* states):state(window,states)
{
	this->Createplayer();
	attributes = new Attributes(player,"PLAYER : ",100.0);
	this->Initbackground();
	ebt=0.0;
	score=0;
	powerup=nullptr;
	this->intilevels();
	direction={0.0f,0.0f};
	enemybullet=nullptr;
}
Singleplayer::~Singleplayer()
{
	
	delete attributes;
	delete powerup;
}
void Singleplayer::Createplayer()
{
	player = new Player(textures["PLAYER"],(sf::Color(255,131,250,255)),textures["BULLET"],sf::Vector2f PLAYERPOS);
}
void Singleplayer::intilevels()
{
	levels.push_back(new Level(textures["ENEMY"],textures["EXPLOSION"],"levelonepositions.txt",&enemies));
	levels.push_back(new Level(textures["ENEMY"],textures["EXPLOSION"],"leveltwopositions.txt",&enemies));
	startlevel();
}
void Singleplayer::Initbackground()
{
	background.setTexture(textures["BACKGROUND"]);
	background.setSize(sf::Vector2f((float)window->getSize().x,(float)window->getSize().y));
	background.setPosition((float)window->getPosition().x,(float)window->getPosition().y);
	background.setFillColor(sf::Color(sf::Color::White.toInteger()));
}
void Singleplayer::startlevel()
{
	if(levels.front())
	{
		levels.front()->start();
	}
}
void Singleplayer::CreateBullet(float dt)
{	
	if(player)
	{
		player->createbullet();		
	}
}
void Singleplayer::CreateEnemyBullet(sf::Vector2f pos)
{
	if(!player->isinvisible() && ebt>TIMEBETWEENBULLETS)
	enemybullet=(new Bullet(textures["ENEMYBULLET"],pos,-1.0f,sf::Color::Yellow,1.2*BULLETSPEED));
}

void Singleplayer::Createpowerup()
{
	int a= rand()%3;
	
	switch(a)
	{
		case 0: 
		{
			if(poweruptime>POWERUPTIME)
			{
			poweruptime=0;
			if(!powerup)
			{
			float xpos=rand()%(window->getSize().x-100);
			powerup=new Shield(textures["SHIELD"],sf::Vector2f(xpos,-20));
			type=SHIELD;
			}
			}
			
			break;
		}
		case 1:
		{
			if(poweruptime>POWERUPTIME)
			{
			poweruptime=0;
			if(!powerup)
			{
			float xpos=rand()%(window->getSize().x-100);
			powerup=new Invisible(textures["INVISIBLE"],sf::Vector2f(xpos,-20));
			type=INVISIBILTY;
			}
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
			}
			
			break;
		}
	}
}

bool Singleplayer::CheckPlayerBounds()
{

	if(player->getpos().x>=0 && player->getpos().x<=window->getSize().x)
	{
		return true;
	}
	else if(player->getpos().x<0)
	{
		player->setpos(sf::Vector2f(30,player->getpos().y));
	}
	else if(player->getpos().x>window->getSize().x)
	{
		player->setpos(sf::Vector2f( window->getSize().x-30,player->getpos().y));
	
	}
	return false;
	
}
void Singleplayer::updateinput(float dt)
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
		if(player)
		player->createbullet();
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		states->push(new Pause(window,states,&quit));
	}
	if(player)
	{
		if(CheckPlayerBounds())
		{
			player->move(direction,dt);
		}
	}
	
}
void Singleplayer::updatecollison()
{
			
	unsigned index=0;
	for(auto i=enemies.begin();i!=enemies.end() && index<enemies.size();i++)
	{
			
			
	if(player->checkhitenemy(enemies[index]))
	{
	
		player->increasescore();
		enemies[index]->onCollison();
		break;

	}
			
	index++;
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
void Singleplayer::updatebullets()
{
	
	if(!enemybullet)
	{
		
		if(getnearestenemy()>=0)
		{
		CreateEnemyBullet(enemies[getnearestenemy()]->getpos());
		}
	}
	if(enemybullet)
	{
	if(enemybullet->getpos().y>window->getSize().y)
	{
		delete enemybullet;
		enemybullet=nullptr;
		
	}	
	}
	
}
void Singleplayer::checkcatchedpowerup()
{
	if(powerup)
	{
		if(powerup->getcollider().checkcollison(player->getcollider()))
		{
			delete powerup;
			powerup=nullptr;
			player->equip(type);
		}
	}
}
void Singleplayer::levelupdates()
{
	if(levels.empty())
	{
		this->endstate();
	}
	else 
	{
		if(levels.front()->getlevel())
		{
			delete enemybullet;
			enemybullet=nullptr;
			
			delete levels.front();
			levels.pop_front();
			score+=player->getscore();
			player->reset();
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

				this->startlevel();	
			}
		}
		
		else 
		{
			levels.front()->update();
		}
	}
}
void Singleplayer::Deletepowerup()
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

void Singleplayer::update(float dt)
{
	
	levelupdates();
	ebt+=dt;
	updateinput(dt);
	poweruptime+=dt;
	Createpowerup();
	attributes->update(dt);
	if(player)
	{
	player->update(dt);
	}
	for(auto& a:enemies)
	{
		a->update(dt);
	}
	if(powerup)
	{
		powerup->update(dt);
	}
	updatebullets();	
	if(enemybullet)
	{
		enemybullet->update(dt);
	}
	checkcatchedpowerup();
	Deletepowerup();
	updatecollison();
	checkplayersafety();
	Checkcollisonwithbullets();
	
}
void Singleplayer::Checkcollisonwithbullets()
{
	if(enemybullet && player)
	{
	if(player->checkhitbullet(enemybullet))
	{
		delete enemybullet;
		enemybullet=nullptr;
	
	}
	}
}
void Singleplayer::checkplayersafety()
{
	if(enemybullet && player)
	{
	if(enemybullet->getcollider().checkcollison(player->getcollider()))
	{
		if(!player->hasshield())
		player->incrementkill();
		delete enemybullet;
		enemybullet=nullptr;
		
		
	}
	}
	if(player->getkill()==0)
	{
		delete player;
		player=nullptr;
	}
	if(!player)
	{
		states->push(new Gameover(window,states,&quit));
	}
}

int Singleplayer::getnearestenemy()
{
	float min;
	if(enemies.size()>0 && player)
	{
	min=INT64_MAX;
	int store=0;
	for(unsigned i=0;i<enemies.size();i++)
	{
		if(abs(enemies[i]->getpos().x-player->getpos().x)<=min)
		{
			min=abs(enemies[i]->getpos().x-player->getpos().x);
			store=i;
		}
	
	}
	
	return store;
	}
	return -1;
}	
void Singleplayer::render()
{
	window->draw(background);
	for(auto& a:enemies)
	{
		a->render(window);
	}
	
	attributes->render(window);
	if(player)
	{
	
	player->render(window);
	}
	if(enemybullet)
	{
		enemybullet->render(window);
	}
	if(powerup)
	{
		powerup->render(window);
	}
	
}


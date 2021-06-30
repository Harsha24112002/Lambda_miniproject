#include "Singleplayer.h"
#include<iostream>
#include<stdexcept>
#include "Leveltwo.h"

Singleplayer::Singleplayer(sf::RenderWindow* window,std::stack<state*>* states):state(window,states)
{
	player = new Player(textures["PLAYER"],sf::Color::Cyan);

	ammo1.setPosition(window->getSize().x-100,window->getSize().y-100);
	ammo1.setSize(sf::Vector2f(50.f,20.0f));
	std::cout<<window->getSize().x;
	ammo1.setOutlineThickness(3);
	ammo1.setOutlineColor(sf::Color::White);
	ammo1.setFillColor(sf::Color::Green);
	this->intilevels();
	gonext=true;
	direction={0.0f,0.0f};
	enemybullet=nullptr;
}
Singleplayer::~Singleplayer()
{
	
	for(auto& a: enemies)
	{
		delete a;
	}
}
void Singleplayer::intilevels()
{
	levels.push_front(new Leveltwo(textures["ENEMY"],&levels,&enemies));
	levels.push_front(new Levelone(textures["ENEMY"],&levels,&enemies));
	startlevel();
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
	enemybullet=(new Bullet(textures["ENEMYBULLET"],pos,-1.0f,sf::Color::White,5));
}

bool Singleplayer::CheckPlayerBounds()
{

	if(player->getpos().x>=0 && player->getpos().x<=window->getSize().x)
	{
		return true;
	}
	else if(player->getpos().x<0)
	{
		player->setpos(sf::Vector2f(20,player->getpos().y));
	}
	else if(player->getpos().x>window->getSize().x)
	{
		player->setpos(sf::Vector2f( window->getSize().x-20,player->getpos().y));
	
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
			//bullets.clear();
			
			delete levels.front();
			levels.pop_front();
				
			if(levels.empty())
			{
				this->endstate();
			}
			else
			{
				states->push(new Levelup(window,states,gonext));
				if(!gonext)
				{
					//levels.push_front(new Levelone(textures["ENEMY"],&levels,&enemies));
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
void Singleplayer::update(float dt)
{
	
	levelupdates();
	totaltime+=dt;
	updateinput(dt);

	if(player)
	{
	player->update(dt);
	}
	for(auto& a:enemies)
	{
		a->update(dt);
	}
	/*for(auto& b:bullets)
	{
		b->update(dt);
	}*/
	updatebullets();	
	if(enemybullet)
	{
		enemybullet->update(dt);
	}
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
		playerhit++;
		delete enemybullet;
		enemybullet=nullptr;
		std::cout<<"R"<<std::endl;
		
	}
	}
	if(playerhit==3)
	{
		delete player;
		player=nullptr;
	}
	if(!player)
	{
		this->endstate();
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
		if(abs(enemies[i]->getpos().x-player->getpos().x)<min)
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
	
	for(auto& a:enemies)
	{
		a->render(window);
	}
	/*for(auto & b:bullets)
	{
		b->render(window);
	}*/
	
	if(player)
	{
	
	player->render(window);
	}
	if(enemybullet)
	{
		enemybullet->render(window);
	}
	/*for(unsigned i=0;i<2-bullets.size();i++)
	{
		ammo1.setPosition(window->getSize().x-100,window->getSize().y-100-20*i);
		window->draw(ammo1);
	}*/
}
/*bool Singleplayer::levelover()
{
	if(player)
	{
		if(this->enemies.empty())
		{
			return true;
		}
	}
	return false;
}*/
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
	this->initvariables();
}
Dualplayer::~Dualplayer()
{
	
	for(auto& a: enemies)
	{
		delete a;
	}
	
}

void Dualplayer::initvariables()
{
	gonext=true;
	direction={0.0f,0.0f};
	direction2={0.0f,0.0f};
	enemybullet1=nullptr;
	enemybullet2=nullptr;
	totaltime=0.0f;
	totaltime2=0.0f;
	revivetime=0.0f;
	player1->textformat("PLAYER 1 :",sf::Vector2f(window->getSize().x-300,100));
	player2->textformat("PLAYER 2 :",sf::Vector2f(window->getSize().x-300,200));

}

void Dualplayer::CreatePlayer1()
{
	if(!player1)
	player1 = new Player(textures["PLAYER"],sf::Color::Cyan);
}
void Dualplayer::CreatePlayer2()
{
	if(!player2)
	player2=new Player(textures["PLAYER"],sf::Color(255,165,0,255));
}
void Dualplayer::intilevels()
{
	levels.push_front(new Leveltwo(textures["ENEMY"],&levels,&enemies));
	levels.push_front(new Levelone(textures["ENEMY"],&levels,&enemies));
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
	if(!enemybullet1)
	enemybullet1=(new Bullet(textures["ENEMYBULLET"],pos,-1.0f,sf::Color::White,5));
}

void Dualplayer::CreateEnemyBullet2(sf::Vector2f pos)
{
	if(!enemybullet2 )
	enemybullet2=new Bullet(textures["ENEMYBULLET"],pos,-1.0f,sf::Color::White,5);
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
			delete enemybullet1;
			enemybullet1=nullptr;
			
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
		if(revivetime>100)
		{
			CreatePlayer1();
		}
	}
	if(!player2)
	{
		if(revivetime>100)
		{
			CreatePlayer2();
		}
	}
} 
void Dualplayer::update(float dt)
{
	
	levelupdates();
	totaltime+=dt;
	totaltime2+=dt;
	Rebirth(dt);
	updateinput(dt);
	updateinputtwo(dt);
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
	updatecollison();
	checkplayersafety(enemybullet1);
	checkplayersafety(enemybullet2);
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
void Dualplayer::checkplayersafety(Bullet* enemybullet)
{
	if(enemybullet)
	{
	if(player1)
	{
	if(enemybullet->getcollider().checkcollison(player1->getcollider()))
	{
		delete player1;
		player1=nullptr;
		
	}
	}
	if(player2)
	{
	if(enemybullet->getcollider().checkcollison(player2->getcollider()))
	{
		delete player2;
		player2=nullptr;
		
	}
	}
	}
	if(!player1 && !player2)
	{
		this->endstate();
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
		if(abs(enemies[i]->getpos().x-player1->getpos().x)<min)
		{
			min=abs(enemies[i]->getpos().x-player1->getpos().x);
			store=i;
		}
	
	}
	
	return store;
	}
	return -1;
}	
void Dualplayer::render()
{
	
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
	if(enemybullet1)
	{
		enemybullet1->render(window);
	}
	if(enemybullet2)
	{
		enemybullet2->render(window);
	}
	/*for(unsigned i=0;i<2-bullets1.size();i++)
	{
		ammo1.setPosition(window->getSize().x-100,window->getSize().y-100-20*i);
		window->draw(ammo1);
	}*/
}
/*bool Dualplayer1::levelover()
{
	if(player1)
	{
		if(this->enemies.empty())
		{
			return true;
		}
	}
	return false;
}*/
#include "Player.h"
#include <iostream>
Player::Player(sf::Texture* t,sf::Color color,sf::Texture* bullettex,sf::Vector2f pos)
{
	this->pos=pos;

	body.setTexture(*t);
	body.setPosition(pos);
	body.setColor(color);

	kill=3;
	equip(SHIELD);
	Bulletreltime=0.0f;
	
	
	this->color=color;
	this->movement={0.0f,0.0f};
	this->velocity=PVEL;
	this->bullettex=bullettex;
	this->score=0;
	body.setScale(0.2,0.2);
	body.setOrigin(body.getGlobalBounds().width/2.0,body.getGlobalBounds().height/2);
	invisible=false;
}
Player::~Player()
{
	
}
bool Player::checkhitenemy(Enemy* enemy)
{
	unsigned index=0;
	for(auto it=bullets.begin();it!=bullets.end() && index<bullets.size();it++)
	{
		if(bullets[index]->getcollider().checkcollison(enemy->getcollider()))
			{
				bullets[index]->~Bullet();
				bullets.erase(it);
				return true;
			}

	}
	return false;
}
void Player::equip(Powerups type)
{
	this->type=type;
	if(type==SHIELD)
	{
	shield = new sf::CircleShape(SHIELDSIZE);
	shield->setPosition(body.getPosition());
	shield->setOutlineThickness(10);
	shield->setOutlineColor(sf::Color::Cyan);
	shield->setFillColor(sf::Color::Transparent);
	shieldtime=0;
	}
	else if(type==INVISIBILTY)
	{
		body.setColor(sf::Color(body.getColor().toInteger()-180));
		invisible =true;
		shieldtime=0;
	}
	else if(type==MEDICINE)
	{
		getheal();
		shieldtime=0;
	}
}
void Player::getheal()
{
	kill=3;
}
bool Player::checkhitbullet(Bullet* enemybullet)
{
	unsigned index=0;
	for(auto it=bullets.begin();it!=bullets.end() && index<bullets.size();it++,index++)
	{
		if(bullets[index]->getcollider().checkcollison(enemybullet->getcollider()))
		{
			
			delete bullets[index];
			bullets.erase(it);
			index--;
			return true;
		}
	}
	return false;
}
void Player::createbullet()
{
	if(Bulletreltime>TIMEBETWEENBULLETS ||bullets.size()==0)
	{
	Bulletreltime=0.0f;
	bullets.push_back(new Bullet(bullettex,body.getPosition(),1.0f,sf::Color::White,BULLETSPEED));
	}
}
void Player::increasescore()
{
	score+=5;
}
void Player::reset()
{
	score=0;
	body.setPosition(pos);
	kill=3;
	body.setColor(color);
	equip(SHIELD);
	invisible=false;
}
void Player::move(sf::Vector2f direction,float dt)
{
	
	movement.x=direction.x*velocity*dt;
	movement.y=0;
	
}
void Player::update(float dt)
{
	
	Bulletreltime+=dt;
	shieldtime+=dt;
	if(shieldtime>SHIELDONTIME)
	{
		if(type==0)
		{
		if(shield)
		{
		shieldtime=0;
		delete shield;
		shield =nullptr;
		}
		}
		if(type==1)
		{
			invisible=false;
			body.setColor(color);
		}
	}
	
	if(shield)
	{
		shield->setPosition(body.getPosition().x-20,body.getPosition().y-30);
	}
	body.move(movement);
	updatebullets(dt);
	for(auto& b:bullets)
	{
		b->update(dt);
	}
}
void Player::updatebullets(float dt)
{
	if( bullets.size()>0)
	{
		if(bullets[0]->getpos().y<0)
		{
			bullets[0]->~Bullet();
			bullets.erase(bullets.begin());
		}
	}
}
void Player::render(sf::RenderWindow* window)
{
	window->draw(body);
	for(auto& a: bullets)
	{
		a->render(window);
	}
	if(shield)
	{
		window->draw(*shield);
	}
}

#include "Player.h"
#include <iostream>
Player::Player(sf::Texture* t,sf::Color color)
{
	body.setTexture(*t);
	body.setPosition(500,940);
	body.setColor(color);
	Bulletreltime=0.0f;
	bullettex.loadFromFile("laserBullet.png");
	this->movement={0.0f,0.0f};
	this->velocity=50.0f;
	this->font.loadFromFile("HOMOARAK.TTF");
	s="SCORE : ";
	this->text.setString(s);
	this->text.setCharacterSize(30);
	this->text.setPosition(1400,100);
	this->text.setFillColor(sf::Color::Green);
	this->text.setFont(font);
	this->score=0;
	body.setScale(0.2,0.2);
	body.setOrigin(body.getGlobalBounds().width/2.0,body.getGlobalBounds().height/2);
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
	if(Bulletreltime>TimebetweenBullets ||bullets.size()==0)
	{
	Bulletreltime=0.0f;
	bullets.push_back(new Bullet(&bullettex,body.getPosition(),1.0f,sf::Color::Green,10));
	}
}
void Player::textformat(std::string a,sf::Vector2f pos)
{
	s=a;
	text.setPosition(pos);
}
void Player::increasescore()
{
	score+=5;
}
void Player::move(sf::Vector2f direction,float dt)
{
	
	movement.x=direction.x*velocity*dt;
	movement.y=0;
	
}
void Player::update(float dt)
{
	
	Bulletreltime+=dt;
	text.setString(s+std::to_string(score));
	
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
	window->draw(text);
	for(auto& a: bullets)
	{
		a->render(window);
	}
}

#include "Animation.h"

Animation::Animation(sf::Texture* t, sf::Vector2f pos,float switchtime)
{
	this->pos=pos;
	this->t=t;
	this->switchtime=switchtime;
	this->animation.setTexture(*t);
	this->totaltime=0;
	this->currentimage.x=0;
	this->currentimage.y=0 ;
	this->width=t->getSize().x/NOIMAGES;
	this->height=t->getSize().x/NOIMAGES;
	this->explosiontime=0;
	rect.width=this->width;
	rect.height=this->height;
	rect.top=0;
	rect.left=0;
	animation.setTextureRect(rect);
	this->animation.setPosition(pos);
	animation.setScale(1.2,1.2);
	
}

Animation::~Animation()
{
}

void Animation::update(float dt)
{
	explosiontime+=dt;
	totaltime+=dt;
	if(totaltime>switchtime)
	{
		currentimage.x++;
		if(currentimage.x>NOIMAGES-1)
		{
			currentimage.x=0;
		}
		totaltime=0;
	}
	
	rect.top=currentimage.y*this->height;
	rect.left=currentimage.x*this->width;
	animation.setTextureRect(rect);
}

bool Animation::explosion()
{
	if(explosiontime>MAXTIME) return true;
	 	else return false;
}
void Animation::render(sf::RenderWindow* window)
{
	window->draw(animation);
}
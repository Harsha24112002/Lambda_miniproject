#include "Animation.h"
#include <iostream>
Animation::Animation(sf::Vector2f pos,float switchtime)
{
	this->pos=pos;
	this->t.loadFromFile("exp2_0.png");
	this->switchtime=switchtime;
	this->animation.setTexture(t);
	this->totaltime=0;
	this->currentimage.x=0;
	this->currentimage.y=0 ;
	this->width=t.getSize().x/4;
	this->height=t.getSize().x/4;
	this->explosiontime=0;
	rect.width=this->width;
	rect.height=this->height;
	rect.top=0;
	rect.left=0;
	animation.setTextureRect(rect);
	this->animation.setPosition(pos);
	
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
		if(currentimage.x>3)
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
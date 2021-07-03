#include "Option.h"
Option::Option(std::string name,sf::Vector2f pos,sf::Vector2f size)
{
	this->position=pos;
	this->size=size;
	this->button.setSize(size);
	this->button.setPosition(position);
	this->font.loadFromFile("HOMOARAK.TTF");
	this->text.setCharacterSize(50);
	this->text.setString(name);
	this->text.setFont(font);
	this->text.setPosition(button.getPosition());
	this->button.setFillColor(sf::Color::Transparent);
}
void Option::update(sf::Vector2i mousepos)
{
	if(button.getGlobalBounds().contains((float)mousepos.x,(float)mousepos.y))
	{
		bt=Hover;
		if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			bt=Pressed;
		}
	}
	else bt=Idle;

	switch(bt)
	{
	case Idle:
		text.setFillColor(sf::Color::Blue);
		text.setCharacterSize(50);break;
	case Hover:
		text.setCharacterSize(60);
		text.setFillColor(sf::Color::White);break;
	case Pressed:
		text.setFillColor(sf::Color::White);
		text.setCharacterSize(50);break;
	default:
		text.setFillColor(sf::Color::Blue);
		text.setCharacterSize(50);
	}
}

void Option::render(sf::RenderWindow* window)
{
	window->draw(button);
	window->draw(text);
}
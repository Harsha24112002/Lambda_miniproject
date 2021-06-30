#ifndef OPTION_H
#define OPTION_H
#include<SFML/Graphics.hpp>
#include <string>
enum buttonstate {Idle,Hover,Pressed};
class Option
{
	private:
	sf::RectangleShape button;
	sf::Text text;
	sf::Font font;
	sf::Vector2f position;
	sf::Vector2f size;
	buttonstate bt;

	public:
	Option(std::string,sf::Vector2f,sf::Vector2f);
	void update(sf::Vector2i mousepos);
	void render(sf::RenderWindow* window);
	bool buttonpressed(){if(bt==Pressed) return true; else return false;}
};
#endif
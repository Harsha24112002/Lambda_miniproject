#ifndef BOUNDRECT_H
#define BOUNDRECT_H
#include <SFML/Graphics.hpp>

class BoundRect
{
	private:
	sf::RectangleShape bound;
	sf::Sprite& sprite;

	public:
	BoundRect(sf::Sprite& sprite,sf::Vector2f offset,sf::Vector2f size);
	void render(sf::RenderWindow* window);
	void update();
};


#endif
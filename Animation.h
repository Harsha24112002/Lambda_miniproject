#ifndef ANIMATION_H
#define ANIMATION_H
#define MAXTIME  0.35f
#define NOIMAGES 4
#include <SFML/Graphics.hpp>

class Animation
{
	private:
	float switchtime;
	float totaltime;
	sf::Vector2f pos;
	sf::Vector2f currentimage;
	sf::Sprite animation;
	sf::Texture* t;
	sf::Rect<int> rect;
	float width;
	float height;
	float explosiontime;
	public:
	Animation(sf::Texture* t,sf::Vector2f pos,float switchtime);
	 ~Animation();
	void update(float dt);
	void render(sf::RenderWindow* window);
	bool explosion();
};
#endif
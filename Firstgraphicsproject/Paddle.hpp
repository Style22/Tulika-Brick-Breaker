#pragma once
#include <SFML/Graphics.hpp>

class Paddle
{
public:
	Paddle();
	Paddle(sf::Texture* texture);
	sf::Sprite paddleSprite;

	// refers to the centre rectangle
	// position of object
	float sourceX = 8;
	float sourceY = 150;
	float sourceW = 64;
	float sourceH = 20;

	float edgeSize = 0;
	float paddleSpeed = 500;

	sf::Vector2f position;
	sf::Vector2f velocity;

	// object rectangles
	sf::FloatRect rect;

	// debug
	bool drawDebug = false;
	sf::RectangleShape debugRectangle;
	sf::RectangleShape debugLeftRectangle;
	sf::RectangleShape debugRightRectangle;

	//function update
	void update(float deltaTime);

	//function draw
	void draw(sf::RenderWindow* window);


};

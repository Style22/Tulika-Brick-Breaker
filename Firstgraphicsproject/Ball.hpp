#pragma once
#include <SFML/Graphics.hpp>
#include "Paddle.hpp"

class Ball
{
public:
	Ball();
	Ball(sf::Texture* texture);
	std::string lastCollision = "wall";
	int* gameState;
	float speed = 500;
	float boundryX = 800;
	//float boundryX = 650;
	float boundryY = 600;
	float angle = 0;
	float maxAngleOfReflection = 0.6f;

	sf::Vector2f velocity;
	sf::Vector2f direction;

	sf::Sprite ballSprite;
	//position of object
	sf::Vector2f position;

	int lastHitIDS[2];

	//object rectangle
	sf::FloatRect rect;
	Paddle* paddle;

	// debug
	bool drawDebug = false;
	sf::RectangleShape debugRectangle;

	//function update
	void update(float deltaTime);

	//function draw
	void draw(sf::RenderWindow* window);
};

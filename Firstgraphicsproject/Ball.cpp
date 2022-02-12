#include "Ball.hpp"
#include <iostream>
#include "Utils.hpp"

# define PI 3.14159265358979323846  /* pi */

Ball::Ball()
{
}

Ball::Ball(sf::Texture* texture)
{
	lastHitIDS[0] = -1;
	lastHitIDS[1] = -1;
	ballSprite.setTexture(*texture);
	ballSprite.setTextureRect(sf::IntRect(48, 136, 8, 8));
	ballSprite.setScale(2, 2);

	rect = sf::FloatRect(position.x, position.y, 16, 16);
	direction = sf::Vector2f(-0.1, 0.1);

	debugRectangle.setSize(sf::Vector2f(16, 16));
	debugRectangle.setFillColor(sf::Color::Red);
	debugRectangle.setPosition(position.x, position.y);
}

void Ball::update(float deltaTime)
{
	sf::Vector2f ndir = Utils::normalize(direction);
	velocity = ndir * speed * deltaTime;

	position.x += velocity.x;
	position.y += velocity.y;

	rect = sf::FloatRect(position.x, position.y, 16, 16);

	if (rect.intersects(paddle->rect) && lastCollision != "paddle")
	{
		float rel = (paddle->position.x + (paddle->rect.width / 2)) - (position.x + (rect.width / 2));
		float norm = rel / (paddle->rect.width / 2);
		double bounce = norm;

		if (bounce > maxAngleOfReflection)
			bounce = maxAngleOfReflection;
		if (bounce < -maxAngleOfReflection)
			bounce = -maxAngleOfReflection;

		direction.x = -sin(bounce);
		direction.y = -cos(bounce);

		lastCollision = "paddle";
	}

	if (position.x + rect.width > boundryX && lastCollision != "wallRight")
	{
		direction.x = direction.x * -1;
		position.x = boundryX - rect.width;
		lastCollision = "wallRight";
	}
	else if (position.x < 0 && lastCollision != "wallLeft")
	{
		direction.x = direction.x * -1;
		position.x = 0;
		lastCollision = "wallLeft";
	}

	if (position.y < 0 && lastCollision != "wallTop")
	{
		direction.y = direction.y * -1;
		position.y = 0;
		lastCollision = "wallTop";
	}

	else if (position.y + rect.height > boundryY && lastCollision != "wallBottom")
	{
		*gameState = 0;
		position = sf::Vector2f(300,200);
	}
	
	ballSprite.setPosition(position);
}

void Ball::draw(sf::RenderWindow* window)
{
	window->draw(ballSprite);
	if (drawDebug)
		window->draw(debugRectangle);
}
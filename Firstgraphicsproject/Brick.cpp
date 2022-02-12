#include "Brick.hpp"
#include <iostream>

Brick::Brick()
{
}

Brick::Brick(sf::Texture* texture, std::vector<sf::Vector2f> states)
{
	brickSprite.setTexture(*texture);
	brickSprite.setTextureRect(sf::IntRect(states[0].x, states[0].y, 32, 16));
	brickSprite.setScale(1, 1);
	rect = sf::FloatRect(position.x, position.y, 32, 24);
	brickSprite.setPosition(position.x, position.y);

	rectangle.setSize(sf::Vector2f(32, 24));
	rectangle.setFillColor(sf::Color::Red);
	rectangle.setPosition(position.x, position.y);

	isAlive = true;
	this->states = states;
}


void Brick::draw(sf::RenderWindow* window)
{
	window->draw(brickSprite);
	if (drawDebug)
		window->draw(rectangle);
}

void Brick::Hit()
{
	currentState += 1;
	if (currentState >= states.size())
	{
		markedDead = true;
	}
	else
	{
		brickSprite.setTextureRect(sf::IntRect(states[currentState].x, states[currentState].y, 32, 16));
	}
}

void Brick::UpdateBrickPosition(sf::Vector2f pos)
{
	position = pos;
	rect = sf::FloatRect(position.x, position.y, 32, 24);
	brickSprite.setPosition(position.x, position.y);

	rectangle.setSize(sf::Vector2f(32, 24));
	rectangle.setFillColor(sf::Color::Red);
	rectangle.setPosition(position.x, position.y);
}
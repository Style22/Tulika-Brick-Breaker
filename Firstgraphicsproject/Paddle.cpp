#include "Paddle.hpp"

Paddle::Paddle()
{
}

Paddle::Paddle(sf::Texture* texture)
{
	paddleSprite.setTexture(*texture);
	paddleSprite.setTextureRect(sf::IntRect(sourceX, sourceY, sourceW, sourceH));

	rect = sf::FloatRect(position.x, position.y, sourceW - (edgeSize * 2), sourceH);

	debugRectangle.setSize(sf::Vector2f(sourceW - (edgeSize * 2), sourceH));
	debugRectangle.setFillColor(sf::Color::Red);

	debugLeftRectangle.setSize(sf::Vector2f(edgeSize, sourceH));
	debugLeftRectangle.setFillColor(sf::Color::Blue);

	debugRightRectangle.setSize(sf::Vector2f(edgeSize, sourceH));
	debugRightRectangle.setFillColor(sf::Color::Yellow);
}

void Paddle::update(float deltaTime)
{
	position.x += paddleSpeed * velocity.x * deltaTime;
	position.y += paddleSpeed * velocity.y * deltaTime;

	rect = sf::FloatRect(position.x + edgeSize, position.y, sourceW - (edgeSize * 2), sourceH);

	paddleSprite.setPosition(position);
	debugRectangle.setPosition(position.x + edgeSize, position.y);
	debugLeftRectangle.setPosition(position.x, position.y);
	debugRightRectangle.setPosition((position.x + sourceW) - edgeSize, position.y);

}

void Paddle::draw(sf::RenderWindow* window)
{
	window->draw(paddleSprite);
	if (drawDebug)
	{
		window->draw(debugRectangle);
		window->draw(debugLeftRectangle);
		window->draw(debugRightRectangle);
	}
}
#pragma once
#include "Utils.hpp"
#include "Paddle.hpp"
#include "Ball.hpp"
#include "Brick.hpp"

class Game
{
public:
	Game();
	sf::Texture fullTexture;
	Paddle paddle;
	Ball ball;
	Brick brick;
	float deltaTime;
	sf::Clock deltaClock;
	int lastHitBrick = -1;
	float hitBufferTime = 0.01f;
	float hitBufferTimer = 0.0f;

	int gameState = 0;

	std::map<int, Brick*> brickMap;

	void run(sf::RenderWindow* window);

};



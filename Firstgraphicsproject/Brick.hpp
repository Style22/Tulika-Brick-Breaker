#pragma once
#include <SFML/Graphics.hpp>

class Brick
{
public:
	Brick();
	Brick(sf::Texture* texture, std::vector<sf::Vector2f> states);

	std::vector<sf::Vector2f> states;

	sf::Sprite brickSprite;
	// position of object
	sf::Vector2f position;

	// object rectangle
	sf::FloatRect rect;
	sf::FloatRect* playerRect;
	int brickID;
	bool isAlive;
	bool markedDead;
	bool leftRightFromBall = false;
	float deathTimer = 0.0f;

	// debug
	bool drawDebug = false;
	sf::RectangleShape rectangle;

	int currentState = 0;
	std::map<int, Brick*>* brickMap;
	//function draw
	void draw(sf::RenderWindow* window);
	void Hit();
	void UpdateBrickPosition(sf::Vector2f pos);
};
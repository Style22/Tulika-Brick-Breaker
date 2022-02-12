#include "Game.hpp"
#include <iostream>

Game::Game()
{
    if (!fullTexture.loadFromFile("breakout_pieces.png"))
    {

    }

    paddle = Paddle(&fullTexture);
    paddle.position = sf::Vector2f(392, 550);

    ball = Ball(&fullTexture);
    //ball.position = sf::Vector2f(392, 308);
    ball.position = sf::Vector2f(400, 300);
    ball.paddle = &paddle;
    ball.gameState = &gameState;
}

void Game::run(sf::RenderWindow* window)
{
    while (window->isOpen())
    {
        hitBufferTimer += deltaTime;

        sf::Event event;
        while (window->pollEvent(event))
            if (event.type == sf::Event::Closed)
                window->close();
      
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && paddle.position.x > 0)
            paddle.velocity.x = -1;
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && paddle.position.x + paddle.rect.width < 800)
            paddle.velocity.x = 1;
        else
            paddle.velocity.x = 0;

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && gameState == 0)
            gameState = 1;

        if (gameState == 1)
        {
            // updating        
            paddle.update(deltaTime);
            ball.update(deltaTime);

            // ball - brick collision
            for (auto const& x : brickMap)
            {
                if (x.second->isAlive)
                {
                    float ballX = ball.position.x;
                    float ballW = ball.rect.width;
                    float brickX = x.second->position.x;
                    float brickW = x.second->rect.width;
                    int brickID = x.second->brickID;

                    if (ball.rect.intersects(x.second->rect) && hitBufferTimer >= hitBufferTime) {

                        if (ball.lastCollision == "brick" && lastHitBrick == brickID)
                            break;

                        ball.lastCollision = "brick";

                        if (x.second->leftRightFromBall)
                        {
                            std::cout << "left/right hit" << brickID << std::endl;
                            ball.direction.x = ball.direction.x * -1;
                            lastHitBrick = brickID;
                            x.second->Hit();
                            hitBufferTimer = 0.0f;
                            break;
                        }
                        else
                        {
                            std::cout << "top/bottom hit" << brickID << std::endl;
                            ball.direction.y = ball.direction.y * -1;
                            lastHitBrick = brickID;
                            x.second->Hit();
                            hitBufferTimer = 0.0f;
                            break;
                        }
                    }
                    else
                    {
                        if ((ballX > brickX + brickW || ballX + ballW < brickX))
                            x.second->leftRightFromBall = true;
                        else
                            x.second->leftRightFromBall = false;
                    }
                }
            }


        }

        // drawing
        if (gameState == 1)
        {
            window->clear();


            paddle.draw(window);
            ball.draw(window);

            for (auto const& x : brickMap)
            {
                if (x.second->markedDead)
                {
                    x.second->deathTimer += deltaTime;
                    if (x.second->deathTimer > 0.1f)
                        x.second->isAlive = false;
                }
                if (x.second->isAlive)
                    x.second->draw(window);
            }


            window->display();
        }
        deltaTime = deltaClock.restart().asSeconds();
    }
}
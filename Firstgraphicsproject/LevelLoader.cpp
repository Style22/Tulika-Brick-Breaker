#include "LevelLoader.hpp"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void LevelLoader::Loader()
{
    string line;
    ifstream myfile("example.txt");
    int columnTracker = 0;
    int rowTracker = 0;
    int index = 0;

    std::vector<sf::Vector2f> brickType2States = {
     sf::Vector2f(8, 28),
    };

    std::vector<sf::Vector2f> brickType1States = {
        sf::Vector2f(8, 8),
        sf::Vector2f(48, 8),
        sf::Vector2f(8, 28),
    };


    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {
            for (int i = 0; i < line.size(); i++)
            {
                if (line[i] != ',')
                {

                    Brick* newBrick = new Brick();
                    if (line[i] == '1')
                        newBrick = new Brick(&game->fullTexture, brickType1States);
                    else if (line[i] == '2')
                        newBrick = new Brick(&game->fullTexture, brickType1States);

                    sf::Vector2f newPosition = sf::Vector2f(0 + (32 * columnTracker), 0 + (16 * rowTracker));
                    newBrick->UpdateBrickPosition(newPosition);
                    newBrick->brickMap = &game->brickMap;
                    newBrick->brickID = index;
                    game->brickMap.insert(std::make_pair(index, newBrick));
                    columnTracker += 1;
                    index++;

                }
            }
            rowTracker += 1;
            columnTracker = 0;
        }
        myfile.close();
    }

    else cout << "Unable to open file";
}
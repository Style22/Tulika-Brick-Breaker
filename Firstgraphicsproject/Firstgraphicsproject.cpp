#include "Game.hpp"
#include "LevelLoader.hpp"
#include <unordered_map>

namespace standard = std;

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "C++ Brick Breaker By: Tulika");

    LevelLoader L = LevelLoader();
    Game g = Game();
    L.game = &g;
    L.Loader();
    g.run(&window);

    return 0;
}
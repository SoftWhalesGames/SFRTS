#include <SFML/Graphics.hpp>
#include "game_app/game_app.h"

int main()
{
    auto window = sf::RenderWindow(sf::VideoMode({800u, 600u}), "CMake SFML Project");
    game_app* app = new game_app(&window);

    app->run();
    
    return EXIT_SUCCESS;
}

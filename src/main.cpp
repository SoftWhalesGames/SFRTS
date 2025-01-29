#include <SFML/Graphics.hpp>
#include "GameApp/GameApp.hpp"
#include "..\build\_deps\imgui-src\imgui.h"

int main()
{
    auto window = sf::RenderWindow(sf::VideoMode({800u, 600u}), "CMake SFML Project");
    GameApp *app = new GameApp(&window);

    app->run();

    return EXIT_SUCCESS;
}

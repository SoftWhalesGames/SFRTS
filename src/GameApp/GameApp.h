
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>


#ifndef GAME_APP_H
#define GAME_APP_H

class GameApp // TODO UPDATE STRUCTURE DECLARATION
{
public:
    GameApp();
    GameApp(sf::RenderWindow* window);

    void handleInput();
    void draw();
    void update();
    void run();

private:
    sf::RenderWindow* m_window;
    sf::Clock m_clock;
};

#endif // GAME_APP_H


#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>


#ifndef GAME_APP_H
#define GAME_APP_H

class game_app // TODO UPDATE STRUCTURE DECLARATION
{
public:
    game_app();
    game_app(sf::RenderWindow* window);

    void handle_input();
    void draw();
    void update();
    void run();

private:
    sf::RenderWindow* m_window;
    sf::Clock m_clock;
};

#endif // GAME_APP_H

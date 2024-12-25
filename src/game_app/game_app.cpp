
#include "game_app.h"

game_app::game_app() {}

game_app::game_app(sf::RenderWindow* window) // TODO UPDATE IMPLEMENTATION
{
    m_window = window;
}

void game_app::handle_input()
{
    sf::Event _event;
    while (m_window->pollEvent(_event))
    {
        if (_event.type == sf::Event::Closed)
        {
            m_window->close();
        }
        /*
         * input handling implementation
         */
    }
}

void game_app::draw()
{
    m_window->clear();
    /*
     * render implementation
     */
    m_window->display();
}

void game_app::update()
{
    /*
     * update implementation with Box2D))
     */
}

void game_app::run()
{
    while (m_window->isOpen())
    {
        handle_input();
        update();
        draw();
    }
}

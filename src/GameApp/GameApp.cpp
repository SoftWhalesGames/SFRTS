
#include "GameApp.h"

GameApp::GameApp() {}

GameApp::GameApp(sf::RenderWindow* window) // TODO UPDATE IMPLEMENTATION
{
    m_window = window;
}

void GameApp::handleInput()
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

void GameApp::draw()
{
    m_window->clear();
    /*
     * render implementation
     */
    m_window->display();
}

void GameApp::update()
{
    /*
     * update implementation with Box2D))
     */
}

void GameApp::run()
{
    while (m_window->isOpen())
    {
        handleInput();
        update();
        draw();
    }
}

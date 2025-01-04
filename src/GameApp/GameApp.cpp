
#include "GameApp.hpp"

GameApp::GameApp() {}

GameApp::GameApp(sf::RenderWindow* window) // TODO UPDATE IMPLEMENTATION
{
    m_window = window;
    if(!m_animations_texture.loadFromFile(GAME_APP_GET_TEXTURE_PATH("test_animaton.bmp")))
    {
        printf("ERROR");
    }
    m_animations = Animator(&m_animations_texture);
    m_animations.setPositionCallback(
        []()
        {
            return sf::Vector2f{40.f,40.f};
        });

    Animation anim1 = Animation({0,0}, {32,24}, 200, 8);
    m_animations.addAnimation("anim1",anim1);

    Animation anim2 = Animation({0,35},{20,35}, 500,4);
    m_animations.addAnimation("anim2",anim2);

    m_animations.setAnimation("anim1");

}

void GameApp::handleInput()
{
    sf::Event ev;
    while (m_window->pollEvent(ev))
    {
        if (ev.type == sf::Event::Closed)
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
    
    m_animations.draw(m_window);

    m_window->display();
}

void GameApp::update()
{
    float delta = m_clock.restart().asSeconds();
    m_animations.update(delta);
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




#ifndef GAME_APP_H
#define GAME_APP_H

#define GAME_APP_RESOUCE_IMAGE "assets/images"

#define GAME_APP_GET_TEXTURE_PATH(texture_path) GAME_APP_RESOUCE_IMAGE "/" texture_path

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <Animator/Animator.hpp>

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
    sf::Texture m_animations_texture;
    Animator m_animations;
};

#endif // GAME_APP_H

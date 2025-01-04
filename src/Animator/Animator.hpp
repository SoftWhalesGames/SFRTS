
#ifndef ANIMATOR_HPP
#define ANIMATOR_HPP

#include <map>
#include <vector>
#include <SFML/System/String.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <Animation/Animation.hpp>

class Animator{
public:
    Animator();
    Animator(sf::Texture* animation_texture);
    ~Animator();

    void draw(sf::RenderTarget* target);
    void update(float delta);
    void setAnimation(sf::String animation_name);
    void addAnimation(sf::String name, Animation animation);
    void setPosition(sf::Vector2f position);

private:
    std::map<sf::String,Animation> m_offset_by_animation_name;
    sf::Texture* m_animation_set;
    sf::String m_previous_animation;
    sf::String m_current_animation;
    // sf::Vector2f (*m_get_position)(void);
    sf::Vector2f m_animation_position;
};

#endif // ANIMATOR_HPP

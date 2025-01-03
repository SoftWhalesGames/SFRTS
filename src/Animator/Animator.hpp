
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

    void Draw(sf::RenderTarget* target);
    void Update(float delta);
    void SetAnimation(sf::String animation_name);
    void AddAnimation(sf::String name, Animation animation);
    void SetPositionCallback(sf::Vector2f (*get_position)(void));

private:
    std::map<sf::String,Animation> m_offset_by_animation_name;
    sf::Texture* m_animation_set;
    sf::String m_previous_animation;
    sf::String m_current_animation;
    sf::Vector2f (*m_get_position)(void);
};

#endif // ANIMATOR_HPP

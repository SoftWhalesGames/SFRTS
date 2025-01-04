#include "Animator/Animator.hpp"

Animator::Animator()
{
}

Animator::Animator(sf::Texture *animation_texture)
{
    m_animation_set = animation_texture;
    m_offset_by_animation_name = std::map<sf::String, Animation>();
}

Animator::~Animator()
{
}

void Animator::draw(sf::RenderTarget *target)
{
    Animation* animation = &m_offset_by_animation_name.at(m_current_animation);
    sf::Sprite current_frame = animation->getCurrentFrame(m_animation_set);
    sf::Vector2f position = m_get_position();
    current_frame.setPosition(position);
    target->draw(current_frame);
}

void Animator::update(float delta)
{
    Animation* animation = &m_offset_by_animation_name.at(m_current_animation);
    animation->update(delta);
}

void Animator::setAnimation(sf::String animation_name)
{
    m_previous_animation = m_current_animation;
    m_current_animation = animation_name;
    Animation* animation = &m_offset_by_animation_name.at(m_current_animation);
    animation->resetAnimation();
}

void Animator::addAnimation(const sf::String name, Animation animation)
{
    std::pair<sf::String,Animation> pair = std::pair<sf::String,Animation>(name,animation);
    m_offset_by_animation_name.insert(pair);
}

void Animator::setPositionCallback(sf::Vector2f (*get_position)(void))
{
    m_get_position = get_position;
}

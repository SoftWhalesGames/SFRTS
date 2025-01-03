#include "Animator/Animator.hpp"

Animator::Animator()
{
}

Animator::Animator(sf::Texture *animation_texture)
{
    m_animation_set = animation_texture;
    m_offset_by_animation_name = std::map<sf::String, Animation*>();
}

void Animator::Draw(sf::RenderTarget *target)
{
    Animation* animation = m_offset_by_animation_name.at(m_current_animation);
    sf::Sprite current_frame = animation->GetCurrentFrame(m_animation_set);
    target->draw(current_frame);
}

void Animator::Update(float delta)
{
    Animation* animation = m_offset_by_animation_name.at(m_current_animation);
    animation->Update(delta);
}

void Animator::SetAnimation(sf::String animation_name)
{
    m_previous_animation = m_current_animation;
    m_current_animation = animation_name;
}

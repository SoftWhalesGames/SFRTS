#include "Animation/Animation.hpp"

Animation::Animation()
{
}

Animation::Animation(sf::Vector2i base_offset, sf::Vector2i frame_size,
                     uint16_t frame_timeout, uint8_t frame_count)
{
    m_base_offset = base_offset;
    m_frame_size = frame_size;
    m_frame = sf::IntRect(base_offset,frame_size);
    m_frame_count_in_animation = frame_count;
    m_max_frame_timeout = frame_timeout;
    m_frame_timeout = 0;
    m_current_frame = 0;
}

sf::Sprite Animation::GetCurrentFrame(sf::Texture *animations)
{
    sf::Sprite frame;
    frame.setTexture(*animations);
    frame.setTextureRect(m_frame);
    return frame;
}

void Animation::ResetAnimation()
{
    m_frame_timeout = 0;
    m_current_frame = 0;
}

void Animation::Update(float delta)
{
    m_frame_timeout = m_frame_timeout + (uint16_t)(delta * 1000);

    if(m_frame_timeout > m_max_frame_timeout)
    {
        m_frame_timeout = 0;
        m_current_frame = (m_current_frame + 1) % m_frame_count_in_animation;
        
        int32_t offset = m_current_frame * m_frame_size.x;
        m_frame = sf::IntRect(
            {   
                m_base_offset.x + offset,
                m_base_offset.y
            },
            m_frame_size);
    }

}


#ifndef ANIMATION_HPP
#define ANIMATION_HPP

#include <inttypes.h>
#include <SFML/Graphics/Sprite.hpp>

class Animation{
public:
    Animation();
    Animation(  sf::Vector2i base_offset, sf::Vector2i frame_size,
                uint16_t frame_timeout,uint8_t frame_count);

    sf::Sprite GetCurrentFrame(sf::Texture* animations);
    void ResetAnimation();
    void Update(float delta);

private:
    sf::Vector2i m_base_offset;
    sf::Vector2i m_frame_size;
    sf::IntRect m_frame;
    uint16_t m_frame_timeout;
    uint16_t m_max_frame_timeout;
    uint8_t m_frame_count_in_animation;
    uint8_t m_current_frame;

};

#endif // ANIMATION_HPP

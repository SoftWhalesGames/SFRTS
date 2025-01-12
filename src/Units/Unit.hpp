

#ifndef UNIT_HPP
#define UNIT_HPP

#include <map>
#include <cmath>

#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <Animator/Animator.hpp>

enum UnitState
{
    UNIT_STATE_IDLE = 0,
    UNIT_STATE_MOVE,
    UNIT_STATE_TOTAL
};

/// @brief class that represents generic Unit
class Unit
{
public:
    Unit();

    virtual void handleInput(sf::Event ev);
    virtual void update(float delta);
    virtual void draw(sf::RenderTarget* target);

protected:
    sf::Vector2f m_position;
    /// @brief desired position represents where unit desite to be
    sf::Vector2f m_desired_position;
    /// @brief ditection at the momet of set new desired direction
    sf::Vector2f m_direction;
    /// @brief direction to desired position
    sf::Vector2f m_desired_direction;
    float m_current_velocity;
    float m_max_velocity;
    float m_acceleration;
    float m_tolerance;
    float m_angle_degree;
    float m_rotation_speed;    
    Animator m_animator;
    UnitState m_current_state;
    UnitState m_previous_state;
    std::map<UnitState,sf::String> m_state_dictionary;
};

#endif  //  UNIT_HPP
#include "Unit.hpp"

Unit::Unit()
{
}

void Unit::handleInput(sf::Event ev)
{
    if(ev.type == sf::Event::EventType::MouseButtonPressed)
    {
        if(ev.mouseButton.button == sf::Mouse::Button::Right)
        {
            m_desired_position = {
                ev.mouseButton.x,
                ev.mouseButton.y
            }; 
            //  set desired position and recalculate desired direction 
            m_desired_direction = m_desired_position - m_position;
            float magnitude = 
                m_desired_direction.x * m_desired_direction.x +
                m_desired_direction.y * m_desired_direction.y;
            magnitude = sqrtf(magnitude);
            m_desired_direction = m_desired_direction / magnitude;
        }
    }
}

void Unit::update(float delta)
{
    if(m_current_state == UnitState::UNIT_STATE_MOVE)
    {
        m_current_velocity += m_acceleration;
        if(m_current_velocity > m_max_velocity)
        {
            m_current_velocity = m_max_velocity;
        }
        sf::Vector2f turn_direction = m_desired_direction - m_direction;
        float magnitude = sqrtf(
            turn_direction.x * turn_direction.x +
            turn_direction.y * turn_direction.y
        );
        turn_direction = turn_direction / magnitude;

        // diflect direction to desired direction
        m_direction = m_direction + turn_direction * m_rotation_speed * delta;

        sf::Vector2f displacement = m_direction * m_current_velocity * delta;

        m_position += displacement;

        m_animator.setPosition(m_position);
    }
}

void Unit::draw(sf::RenderTarget *target)
{

    m_animator.draw(target);
}

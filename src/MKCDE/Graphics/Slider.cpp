#include <MKCDE/Graphics/Slider.hpp>

#include <cmath>

Slider::Slider() = default;

Slider::Slider(const sf::Texture texture)
{
    m_shape.setTexture(&texture);
    m_shape.setSize(sf::Vector2f(texture.getSize()));
}

void Slider::update(const sf::RenderWindow& window, const sf::Event& event)
{
    sf::Vector2f pos = m_shape.getPosition();
    sf::Vector2f mousePos = sf::Vector2f(sf::Mouse::getPosition(window));
    pos = mousePos;
    auto angle = getRotation() * 3.1415f / 180.0f;
    m_shape.setPosition(
        pos.x * cos(angle) + pos.y * sin(angle),
        -pos.x * sin(angle) + pos.y * cos(angle)
    );
}

void Slider::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    target.draw(m_shape, states);
}

#include <MKCDE/Graphics/Slider.hpp>

#include <cmath>

mk::Slider::Slider() = default;

void mk::Slider::update(const sf::RenderWindow& window, const sf::Event& event)
{

}

void mk::Slider::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    target.draw(m_shape, states);
}

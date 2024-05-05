#include <MKCDE/Graphics/Slider.hpp>

mk::Slider::Slider() = default;

mk::Slider::Slider(const sf::Texture texture)
{
    m_sprite.setTexture(texture, true);
    m_shape.setSize(texture.getSize());
}

void mk::Slider::update(sf::Event& event, sf::RenderWindow& window)
{
    if (event.type == sf::Event::MouseButtonPressed)
    {
        if (event.mouseButton.button == sf::Mouse::Left)
        {
            sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        }
    }
}

void mk::Slider::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    target.draw(m_sprite, states);
    //target.draw(m_shape, states);
}

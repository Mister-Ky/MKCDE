#include <MKCDE/Graphics/Button.hpp>

mk::Button::Button() = default;

mk::Button::Button(const sf::Vector2f& size)
    : m_shape(), m_text()
{
    m_shape.setSize(size);
}

mk::Button::Button(const sf::Vector2f& size, const sf::Font& font)
  : m_shape(), m_text()
{
    m_shape.setSize(size);
    m_text.setFont(font);
    m_text.setCharacterSize(20);
}

sf::RectangleShape* mk::Button::getShape()
{
    return &m_shape;
}

sf::Text* mk::Button::getText()
{
    return &m_text;
}

bool mk::Button::getIsHovered() const
{
    return m_isHovered;
}

void mk::Button::centerText()
{
    mk::centerTextInRectangle(m_shape, m_text);
}

void mk::Button::update(const sf::RenderWindow& window) 
{
    if (m_shape.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
    {
        m_isHovered = true;
    }
    else 
    {
        m_isHovered = false;
    }
}

void mk::Button::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    target.draw(m_shape, states);
    target.draw(m_text, states);
}

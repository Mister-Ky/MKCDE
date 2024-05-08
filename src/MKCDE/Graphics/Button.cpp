#include <MKCDE/Graphics/Button.hpp>

mk::Button::Button() = default;

mk::Button::Button(const sf::Text& text)
  : sf::RectangleShape(), m_text(text)
{
    
}

void mk::Button::setText(const sf::Text& text)
{
    m_text = text;
}

void mk::Button::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(m_text, states);
}

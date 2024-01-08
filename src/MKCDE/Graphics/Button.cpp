#include <MKCDE/Graphics/Button.hpp>

namespace MK
{
Button::Button() : sf::ConvexShape(4) {}

Button::Button(const sf::ConvexShape& shape, const sf::Text& text)
  : m_text(text)
{
}

void Button::setText(const sf::Text& text)
{
  m_text = text;
}

void Button::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
  target.draw(m_text, states);
}
}

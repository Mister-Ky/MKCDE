#include <MKCDE/Graphics/Button.hpp>

namespace MK
{
Button::Button() = default;

Button::Button(const sf::Shape& shape, const sf::Text& text)
  : sf::Shape(shape), m_text(text)
{
}

void Button::setText(const sf::Text& text)
{
  m_text = text;
}

void Button::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
  target.draw(static_cast<const sf::Shape&>(*this), states);
  target.draw(m_text, states);
}
}

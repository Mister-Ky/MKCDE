#include <MKCDE/Graphics/Button.hpp>

namespace MK
{
Button::Button() = default;

Button::Button(const sf::RectangleShape& shape, const sf::Text& text)
  : m_shape(shape), m_text(text)
{
}

Button::~Button() = default;

void Button::setText(const sf::Text& text)
{
  m_text = text;
}

void Button::setShape(const sf::RectangleShape& shape)
{
  m_shape = shape;
}

void Button::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
  states.transform *= getTransform();
  target.draw(m_shape, states);
  target.draw(m_text, states);
}
}

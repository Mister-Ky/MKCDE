#include <MKCDE/Graphics/Button.hpp>

namespace MK
{
Button::Button() = default;

Button::Button(const sf::RectangleShape& shape, const sf::Text& text)
  : m_shape(shape), m_text(text)
{
}

Button::~Button()
{
  
}

void Button::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
  target.draw(m_shape, states);
  target.draw(m_text, states);
}
}

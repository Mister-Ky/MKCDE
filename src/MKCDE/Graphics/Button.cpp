#include <MKCDE/Graphics/Button.hpp>

namespace MK
{
Button::Button() = default;

Button::Button(sf::RectangleShape& shape, sf::Text& text)
{
  this->m_shape = shape;
  this->m_text = text;
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

#include <MKCDE/Graphics/Button.hpp>

namespace MK
{
Button::Button() = default;

void Button::shapeToConvexShape(const sf::Shape* shape)
{
  for (size_t i = 0; i < getPointCount(); i++)
  {
    setPoint(i, shape->getPoint(i));
  }
}

Button::Button(const sf::Shape& shape)
  : sf::ConvexShape(shape.getPointCount()), m_text()
{
  shapeToConvexShape(&shape);
}
Button::Button(const sf::Shape& shape, const sf::Text& text)
  : sf::ConvexShape(shape.getPointCount()), m_text(text)
{
  shapeToConvexShape(&shape);
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

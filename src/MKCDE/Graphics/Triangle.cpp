#include <MKCDE/Graphics/Triangle.hpp>

namespace MK
{
Triangle::Triangle() = default;

Triangle::Triangle(const sf::Vector2f& point1, const sf::Vector2f& point2, const sf::Vector2f& point3)
{
  m_shape.setPointCount(3);
  m_shape.setPoint(0, point1);
  m_shape.setPoint(1, point2);
  m_shape.setPoint(2, point3);
}

Triangle::~Triangle()
{
  
}

void Triangle::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
  target.draw(m_shape, states);
}
}

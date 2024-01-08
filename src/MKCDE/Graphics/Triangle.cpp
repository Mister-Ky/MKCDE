#include <MKCDE/Graphics/Triangle.hpp>

namespace MK
{
Triangle::Triangle() : sf::ConvexShape(3) {}

Triangle::Triangle(const sf::Vector2f& point1, const sf::Vector2f& point2, const sf::Vector2f& point3) : sf::ConvexShape(3)
{
  setPoints(point1, point2, point3);
}

Triangle::~Triangle() = default;

void Triangle::setPoints(const sf::Vector2f& point1, const sf::Vector2f& point2, const sf::Vector2f& point3)
{
  setPoint(0, point1);
  setPoint(1, point2);
  setPoint(2, point3);
}
}

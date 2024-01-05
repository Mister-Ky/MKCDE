#pragma once

#ifndef MK_TRIANGLE_HPP
#define MK_TRIANGLE_HPP

#include <SFML/Graphics.hpp>

namespace MK
{
class Triangle : public sf::Drawable, public sf::Transformable
{
public:
  Triangle();
  Triangle(const sf::Vector2f& point1, const sf::Vector2f& point2, const sf::Vector2f& point3);
  ~Triangle();

  virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
private:
  sf::ConvexShape m_shape;
};
}

#endif

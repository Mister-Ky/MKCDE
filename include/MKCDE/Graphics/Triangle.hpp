#pragma once

#ifndef MK_TRIANGLE_HPP
#define MK_TRIANGLE_HPP

#include <SFML/Graphics.hpp>

namespace MK
{
class Triangle : public sf::ConvexShape
{
public:
  Triangle();
  Triangle(const sf::Vector2f& point1, const sf::Vector2f& point2, const sf::Vector2f& point3);
  ~Triangle();

  void setPoints(const sf::Vector2f& point1, const sf::Vector2f& point2, const sf::Vector2f& point3);
};
}

#endif

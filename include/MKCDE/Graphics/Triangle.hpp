#pragma once

#ifndef MK_TRIANGLE_HPP
#define MK_TRIANGLE_HPP

#include <MKCDE/Graphics/Export.hpp>
#include <SFML/Graphics/ConvexShape.hpp>

namespace mk
{
class MKCDE_GRAPHICS_API Triangle : public sf::ConvexShape
{
public:
    Triangle();
    Triangle(const sf::Vector2f& point1, const sf::Vector2f& point2, const sf::Vector2f& point3);

    void setPoints(const sf::Vector2f& point1, const sf::Vector2f& point2, const sf::Vector2f& point3);
};
}

#endif

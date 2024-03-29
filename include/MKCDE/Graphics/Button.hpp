#pragma once

#ifndef MK_BUTTON_HPP
#define MK_BUTTON_HPP

#include <SFML/Graphics/ConvexShape.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Text.hpp>

namespace mk
{
class Button : public sf::ConvexShape
{
public:
    Button();
    Button(const sf::Shape& shape);
    Button(const sf::Shape& shape, const sf::Text& text);

    void setText(const sf::Text& text);
private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    void shapeToConvexShape(const sf::Shape* shape);

    sf::Text m_text;
};
}

#endif

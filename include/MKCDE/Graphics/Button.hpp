#pragma once

#ifndef MK_BUTTON_HPP
#define MK_BUTTON_HPP

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Text.hpp>

namespace mk
{
class Button : public sf::RectangleShape
{
public:
    Button();
    Button(const sf::Text& text);

    void setText(const sf::Text& text);
private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    sf::Text m_text;
};
}

#endif

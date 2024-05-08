#pragma once

#ifndef MK_BUTTON_HPP
#define MK_BUTTON_HPP

#include <MKCDE/Graphics/Utilities/centerTextInRectangle.hpp>
#include <SFML/Graphics.hpp>
#include <string>

namespace mk
{
class Button : public sf::Transformable, public sf::Drawable
{
public:
    Button();
    Button(const sf::Vector2f& size);
    Button(const sf::Vector2f& size, const sf::Font& font);

    sf::RectangleShape* getShape();
    sf::Text* getText();

    void centerText();
private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    sf::RectangleShape m_shape;
    sf::Text m_text;
};
}

#endif

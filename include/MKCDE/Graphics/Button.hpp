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

    bool getIsHovered() const;
    bool getIsPressed() const;

    void centerText();

    void update(sf::RenderWindow& window);

    sf::Mouse::Button mouseButtonToReact = sf::Mouse::Button::Left;
private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    bool isHovered;
    bool isPressed;

    sf::RectangleShape m_shape;
    sf::Text m_text;
};
}

#endif

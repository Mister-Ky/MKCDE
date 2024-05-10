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

    void centerText();

    void update(const sf::RenderWindow& window);
private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    bool m_isHovered;

    sf::RectangleShape m_shape;
    sf::Text m_text;
};
}

#endif

/// 
/// //button click:
/// 
/// sf::Event event;
/// mk::Button button(sf::Vector2f(width, height));
/// button.update(window);
/// ...
/// while (window.pollEvent(event))
/// {
///     if (event.type == sf::Event::MouseButtonPressed)
///     {
///         if (event.mouseButton.button == sf::Mouse::Left) //mouse button
///         {
///             if (button.getIsHovered())
///             {
///                 //code
///             }
///         }
///     }
/// }
/// window.clear();
/// winwow.draw(button);
/// window.display();
/// 

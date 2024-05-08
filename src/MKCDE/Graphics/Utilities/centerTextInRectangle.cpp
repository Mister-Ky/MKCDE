#include <MKCDE/Graphics/Utilities/centerTextInRectangle.hpp>

void mk::centerTextInRectangle(sf::RectangleShape& rectangle, sf::Text& text)
{
    sf::FloatRect rectBounds = rectangle.getGlobalBounds();
    sf::FloatRect textBounds = text.getGlobalBounds();

    float x = rectBounds.left + (rectBounds.width / 2.0f) - (textBounds.width / 2.0f);
    float y = rectBounds.top + (rectBounds.height / 2.0f) - (textBounds.height / 2.0f);

    text.setPosition(x, y);
}
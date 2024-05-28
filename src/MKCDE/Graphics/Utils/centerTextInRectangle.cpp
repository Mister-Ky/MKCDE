#include <MKCDE/Graphics/Utils/centerTextInRectangle.hpp>

void mk::centerTextInRectangle(sf::RectangleShape& rectangle, sf::Text& text)
{
    sf::FloatRect rectBounds = rectangle.getGlobalBounds();
    sf::FloatRect textBounds = text.getLocalBounds();
    text.setOrigin(textBounds.width / 2.0f, textBounds.height / 2.0f);
    float x = rectBounds.left + (rectBounds.width / 2.0f);
    float y = rectBounds.top + (rectBounds.height / 2.0f);
    text.setPosition(x - textBounds.left, y - textBounds.top);
}

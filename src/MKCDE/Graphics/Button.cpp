#include <MKCDE/Graphics/Button.hpp>

mk::Button::Button() = default;

void mk::Button::shapeToConvexShape(const sf::Shape* shape)
{
    for (size_t i = 0; i < getPointCount(); i++)
    {
        setPoint(i, shape->getPoint(i));
    }
    setFillColor(shape->getFillColor());
    setOrigin(shape->getOrigin());
    setOutlineColor(shape->getOutlineColor());
    setOutlineThickness(shape->getOutlineThickness());
    setPosition(shape->getPosition());
    setRotation(shape->getRotation());
    setScale(shape->getScale());
    setTexture(shape->getTexture());
    setTextureRect(shape->getTextureRect());
}

mk::Button::Button(const sf::Shape& shape)
  : sf::ConvexShape(shape.getPointCount()), m_text()
{
    shapeToConvexShape(&shape);
}
mk::Button::Button(const sf::Shape& shape, const sf::Text& text)
  : sf::ConvexShape(shape.getPointCount()), m_text(text)
{
    shapeToConvexShape(&shape);
}

void mk::Button::setText(const sf::Text& text)
{
    m_text = text;
}

void mk::Button::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    sf::ConvexShape shape(*this);
    target.draw(shape, states);
    target.draw(m_text, states);
}

#pragma once

#ifndef MK_SLIDER_HPP
#define MK_SLIDER_HPP

#include <SFML/Graphics.hpp>

namespace mk
{
class Slider : public sf::Drawable, public sf::Transformable
{
public:
    Slider();
    Slider(const sf::Texture texture);

    void update(sf::Event& event, sf::RenderWindow& window);
private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    sf::RectangleShape m_shape;
    sf::Sprite m_sprite;
};
}

#endif

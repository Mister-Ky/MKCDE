#pragma once

#ifndef MK_SLIDER_HPP
#define MK_SLIDER_HPP

#include <MKCDE/Graphics/Export.hpp>
#include <SFML/Graphics.hpp>

namespace mk
{
class MKCDE_GRAPHICS_API Slider : public sf::Transformable, public sf::Drawable
{
public:
    Slider();

    void update(const sf::RenderWindow& window, const sf::Event& event);
private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    sf::RectangleShape m_shape;
};
}

#endif

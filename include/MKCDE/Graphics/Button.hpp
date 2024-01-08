#pragma once

#ifndef MK_BUTTON_HPP
#define MK_BUTTON_HPP

#include <SFML/Graphics.hpp>

namespace MK
{
class Button : public sf::Shape
{
public:
  Button();
  Button(const sf::Shape& shape, const sf::Text& text);

  void setText(const sf::Text& text);
private:
  virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

  sf::Text m_text;
};
}

#endif

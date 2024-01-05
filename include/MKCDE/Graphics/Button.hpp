#pragma once

#ifndef MK_BUTTON_HPP
#define MK_BUTTON_HPP

#include <SFML/Graphics.hpp>

namespace MK
{
class Button : public sf::Drawable
{
public:
  Button();
  Button(const sf::RectangleShape& shape, const sf::Text& text);
  ~Button();

  void setText(const sf::Text& text);
  void setShape(const sf::RectangleShape& shape);

  virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
private:
  sf::RectangleShape m_shape;
  sf::Text m_text;
};
}

#endif

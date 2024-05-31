#pragma once

#ifndef MK_CENTERTEXTINRECTANGLE_HPP
#define MK_CENTERTEXTINRECTANGLE_HPP

#include <MKCDE/Graphics/Export.hpp>
#include <SFML/Graphics.hpp>

namespace mk
{
MKCDE_GRAPHICS_API void centerTextInRectangle(sf::RectangleShape& rectangle, sf::Text& text);
}

#endif

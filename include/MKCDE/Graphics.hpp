#pragma once

#ifndef MKCDE_GRAPHICS_HPP
#define MKCDE_GRAPHICS_HPP

#include <MKCDE/Graphics/Button.hpp>
#include <MKCDE/Graphics/Slider.hpp>
#include <MKCDE/Graphics/Triangle.hpp>
#include <MKCDE/Graphics/Utils/centerTextInRectangle.hpp>
#include <MKCDE/System.hpp>
#include <SFML/Graphics.hpp>

#if defined(MKCDE_ENABLE_IMGUI_SFML)
#include <imgui.h>
#include <imgui-sfml.h>
#endif
#if defined(MKCDE_ENABLE_TGUI)
#include <TGUI/TGUI.hpp>
#endif

#endif

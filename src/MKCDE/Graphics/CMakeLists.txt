
set(INCROOT ${PROJECT_SOURCE_DIR}/include/MKCDE/Graphics)
set(SRCROOT ${PROJECT_SOURCE_DIR}/src/MKCDE/Graphics)

set(SRC
    ${SRCROOT}/Button.cpp
    ${INCROOT}/Button.hpp
    ${SRCROOT}/Slider.cpp
    ${INCROOT}/Slider.hpp
    ${SRCROOT}/Triangle.cpp
    ${INCROOT}/Triangle.hpp
    ${SRCROOT}/Utils/centerTextInRectangle.cpp
    ${INCROOT}/Utils/centerTextInRectangle.hpp
)

mkcde_add_library(mkcde-graphics SOURCES ${SRC})
target_link_libraries(mkcde-graphics PUBLIC mkcde-system sfml-graphics)

if(MKCDE_ENABLE_IMGUI_SFML)
    target_link_libraries(mkcde-graphics PUBLIC ImGui-SFML::ImGui-SFML)
endif()

if(MKCDE_ENABLE_TGUI)
    target_link_libraries(mkcde-graphics PUBLIC TGUI::TGUI)
endif()

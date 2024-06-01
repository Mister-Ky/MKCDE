
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
    ${SRCROOT}/GraphicalApp.cpp
    ${INCROOT}/GraphicalApp.hpp
)

mkcde_add_library(mkcde-graphics SOURCES ${SRC})
target_link_libraries(mkcde-graphics PUBLIC mkcde-system sfml-graphics ImGui-SFML::ImGui-SFML)

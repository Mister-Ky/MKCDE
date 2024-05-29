
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
    ${SRCROOT}/App/GraphicalApp.cpp
    ${INCROOT}/App/GraphicalApp.hpp
    ${SRCROOT}/App/Data/MKRF.cpp
    ${INCROOT}/App/Data/MKRF.hpp
    ${SRCROOT}/App/Data/Node.cpp
    ${INCROOT}/App/Data/Node.hpp
    ${SRCROOT}/App/Data/NodeTree.cpp
    ${INCROOT}/App/Data/NodeTree.hpp
)

add_library(mkcde-graphics ${SRC})
target_link_libraries(mkcde-graphics PUBLIC mkcde-system sfml-system sfml-window sfml-graphics ImGui-SFML)

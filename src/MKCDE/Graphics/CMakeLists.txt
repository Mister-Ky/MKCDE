
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

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)
FetchContent_Declare(ImGui
    GIT_REPOSITORY https://github.com/ocornut/imgui
    GIT_TAG v1.89.9)
FetchContent_MakeAvailable(ImGui)
FetchContent_GetProperties(ImGui SOURCE_DIR IMGUI_DIR)
set(IMGUI_SFML_FIND_SFML OFF)
FetchContent_Declare(ImGui-SFML
    GIT_REPOSITORY https://github.com/SFML/imgui-sfml
    GIT_TAG 2.6.x)
FetchContent_MakeAvailable(ImGui-SFML)

add_library(mkcde-graphics ${SRC})
target_link_libraries(mkcde-graphics PUBLIC mkcde-system sfml-system sfml-window sfml-graphics ImGui-SFML)

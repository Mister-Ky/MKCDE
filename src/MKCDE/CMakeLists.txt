
include(${PROJECT_SOURCE_DIR}/cmake/Macros.cmake)

#set(LIBRARY_OUTPUT_PATH "${PROJECT_BINARY_DIR}/lib")

#mkcde-system
add_subdirectory(System)

#mkcde-graphics
if(MKCDE_BUILD_GRAPHICS)
    add_subdirectory(Graphics)
endif()

#mkcde-utilities
if(MKCDE_BUILD_UTILS)
    add_subdirectory(Utils)
endif()

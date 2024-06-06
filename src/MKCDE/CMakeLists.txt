
include(${PROJECT_SOURCE_DIR}/cmake/Macros.cmake)

#set(LIBRARY_OUTPUT_PATH "${PROJECT_BINARY_DIR}/lib")

#mkcde-system
add_subdirectory(System)

#mkcde-graphics
if(MKCDE_BUILD_GRAPHICS OR MKCDE_BUILD_APP)
    add_subdirectory(Graphics)
endif()

#mkcde-data
if(MKCDE_BUILD_DATA)
    add_subdirectory(Data)
endif()

#mkcde-utils
if(MKCDE_BUILD_UTILS)
    add_subdirectory(Utils)
endif()

#mkcde-app
if(MKCDE_BUILD_APP)
    add_subdirectory(App)
endif()

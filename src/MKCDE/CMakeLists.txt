
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

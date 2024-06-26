
# thanks to sfml for the cmake sample code for the modular library
# https://github.com/SFML/SFML/blob/2.6.x/CMakeLists.txt
# I changed their code for my library to avoid confusion in the names of objects

cmake_minimum_required(VERSION 3.7.2)

macro(mkcde_set_option var default type docstring)
    if(NOT DEFINED ${var})
        set(${var} ${default})
    endif()
    set(${var} ${${var}} CACHE ${type} ${docstring} FORCE)
endmacro()

set(CMAKE_LEGACY_CYGWIN_WIN32 0)

cmake_policy(SET CMP0042 NEW)
if (NOT CMAKE_VERSION VERSION_LESS 3.9)
    cmake_policy(SET CMP0068 NEW)
endif()

project(MKCDE)

mkcde_set_option(CMAKE_BUILD_TYPE Release STRING "Choose the type of build (Debug or Release)")

set(LIBRARY_OUTPUT_PATH "${PROJECT_BINARY_DIR}/lib")

include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/Config.cmake)

set(VERSION_MAJOR 1)
set(VERSION_MINOR 0)
set(VERSION_PATCH 0)

if(NOT (MKCDE_OS_IOS OR MKCDE_OS_ANDROID))
    mkcde_set_option(BUILD_SHARED_LIBS TRUE BOOL "TRUE to build MKCDE as shared libraries, FALSE to build it as static libraries")
else()
    if(MKCDE_OS_IOS)
        set(BUILD_SHARED_LIBS FALSE)
    elseif(MKCDE_OS_ANDROID)
        set(BUILD_SHARED_LIBS TRUE)
    endif()
endif()

set(CMAKE_CXX_STANDARD 17)

#include_directories("include/")

option(MKCDE_ENABLE_IMGUI_SFML "Enable ImGui-SFML library." OFF)
option(MKCDE_ENABLE_TGUI "Enable TGUI library." OFF)

mkcde_set_option(MKCDE_BUILD_GRAPHICS TRUE BOOL "TRUE to build MKCDE's Graphics module.")
mkcde_set_option(MKCDE_BUILD_DATA TRUE BOOL "TRUE to build MKCDE's Data module.")
mkcde_set_option(MKCDE_BUILD_UTILS TRUE BOOL "TRUE to build MKCDE's Utils module.")
mkcde_set_option(MKCDE_BUILD_APP TRUE BOOL "TRUE to build MKCDE's App module. Uses a Graphics module.")

if(MKCDE_BUILD_APP AND NOT MKCDE_BUILD_GRAPHICS)
    message(WARNING "MKCDE : Forcibly turn on the Graphics module for the App module to work.")
    set(MKCDE_BUILD_GRAPHICS TRUE)
endif()

if(MKCDE_OS_WINDOWS OR MKCDE_OS_IOS)
    set(DEFAULT_INSTALL_MISC_DIR .)
elseif(MKCDE_OS_LINUX OR MKCDE_OS_FREEBSD OR MKCDE_OS_OPENBSD OR MKCDE_OS_NETBSD)
    set(DEFAULT_INSTALL_MISC_DIR share/MKCDE)
elseif(MKCDE_OS_MACOSX)
    set(DEFAULT_INSTALL_MISC_DIR /usr/local/share/MKCDE)
elseif(MKCDE_OS_ANDROID)
    set(DEFAULT_INSTALL_MISC_DIR ${CMAKE_ANDROID_NDK}/sources/third_party/mkcde)
endif()

if(MKCDE_COMPILER_MSVC)
    if(CMAKE_VERSION VERSION_LESS 3.1)
        mkcde_set_option(MKCDE_GENERATE_PDB FALSE BOOL "True to generate PDB debug symbols, FALSE otherwise. Requires CMake 3.1.")
        if(MKCDE_GENERATE_PDB)
            message(FATAL_ERROR "Generation of PDB files (MKCDE_GENERATE_PDB) requires at least CMake 3.1.0")
        endif()
    else()
        mkcde_set_option(MKCDE_GENERATE_PDB TRUE BOOL "True to generate PDB debug symbols, FALSE otherwise. Requires CMake 3.1.")
    endif()

    add_definitions(-D_CRT_SECURE_NO_DEPRECATE -D_SCL_SECURE_NO_WARNINGS)
endif()

set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set_property(GLOBAL PROPERTY PREDEFINED_TARGETS_FOLDER "CMake")

add_subdirectory(src/MKCDE)

if(NOT MKCDE_BUILD_FRAMEWORKS)
    install(DIRECTORY include
            DESTINATION .
            COMPONENT mik
            FILES_MATCHING PATTERN "*.hpp" PATTERN "*.inl")

    if(MKCDE_GENERATE_PDB)
        install(DIRECTORY ${PROJECT_BINARY_DIR}/lib
                DESTINATION .
                COMPONENT mik
                FILES_MATCHING PATTERN "*.pdb")
    endif()
else()
    file(GLOB MKCDE_HEADERS RELATIVE ${PROJECT_SOURCE_DIR} "include/MKCDE/*")

    # what sfml tells us to help:

    # in fact we have to fool cmake to copy all the headers in subdirectories
    # to do that we have to add the "root" headers to the PUBLIC_HEADER
    # then we can run a post script to copy the remaining headers
    # we need a dummy file in order to compile the framework

    #add_custom_command(OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/dummy.cpp
    #                       COMMAND touch ${CMAKE_CURRENT_BINARY_DIR}/dummy.cpp)

    add_custom_command(OUTPUT dummy.cpp
                       COMMAND ${CMAKE_COMMAND} -E copy
                               ${PROJECT_SOURCE_DIR}/tools/dummy.cpp
                               ${CMAKE_CURRENT_BINARY_DIR}/dummy.cpp)

    set(MKCDE_SOURCES ${MKCDE_HEADERS})
    list(APPEND MKCDE_SOURCES ${CMAKE_CURRENT_BINARY_DIR}/dummy.cpp)

    add_library(MKCDE ${MKCDE_SOURCES})

    mkcde_set_stdlib(MKCDE)

    #for mkcde-graphics
    if(MKCDE_ENABLE_IMGUI_SFML)
        target_compile_definitions(MKCDE PUBLIC MKCDE_ENABLE_IMGUI_SFML)
    endif()
    if(MKCDE_ENABLE_TGUI)
        target_compile_definitions(MKCDE PUBLIC MKCDE_ENABLE_TGUI)
    endif()

    #set_target_properties(MKCDE PROPERTIES INSTALL_NAME_DIR "@rpath")
    #if(NOT CMAKE_SKIP_BUILD_RPATH)
    #    if (CMAKE_VERSION VERSION_LESS 3.9)
    #        set_target_properties(MKCDE PROPERTIES BUILD_WITH_INSTALL_RPATH TRUE)
    #    else()
    #        set_target_properties(MKCDE PROPERTIES BUILD_WITH_INSTALL_NAME_DIR TRUE)
    #    endif()
    #endif()

    install(TARGETS MKCDE
            FRAMEWORK DESTINATION "."
            COMPONENT mik)
endif()


# thanks to sfml for the cmake sample code for the modular library
# https://github.com/SFML/SFML/blob/2.6.x/CMakeLists.txt

cmake_minimum_required(VERSION 3.7.2)

if(POLICY CMP0141)
    cmake_policy(SET CMP0141 NEW)
endif()

macro(mkcde_set_option var default type docstring)
    if(NOT DEFINED ${var})
        set(${var} ${default})
    endif()
    set(${var} ${${var}} CACHE ${type} ${docstring} FORCE)
endmacro()

mkcde_set_option(CMAKE_BUILD_TYPE Release STRING "Choose the type of build (Debug or Release)")

project(MKCDE)

include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/Config.cmake)

set(CMAKE_CXX_STANDARD 17)

include_directories("include/")

mkcde_set_option(MKCDE_BUILD_GRAPHICS TRUE BOOL "TRUE to build MKCDE's Graphics module.")
mkcde_set_option(MKCDE_BUILD_UTILS TRUE BOOL "TRUE to build MKCDE's Utils module.")

mkcde_set_option(MKCDE_USE_STATIC_STD_LIBS FALSE BOOL "TRUE to statically link to the standard libraries, FALSE to use them as DLLs")

if(BUILD_SHARED_LIBS AND MKCDE_USE_STATIC_STD_LIBS)
    message(FATAL_ERROR "BUILD_SHARED_LIBS and MKCDE_USE_STATIC_STD_LIBS cannot be used together")
endif()

add_subdirectory(src/MKCDE)

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
                           ${CMAKE_SOURCE_DIR}/tools/dummy.cpp
                           ${CMAKE_CURRENT_BINARY_DIR}/dummy.cpp)

set(MKCDE_SOURCES ${MKCDE_HEADERS})
list(APPEND MKCDE_SOURCES ${CMAKE_CURRENT_BINARY_DIR}/dummy.cpp)

add_library(MKCDE ${MKCDE_SOURCES})

mkcde_set_stdlib(MKCDE)

#headers
add_custom_command(TARGET MKCDE POST_BUILD COMMAND cp -r
                       ${PROJECT_SOURCE_DIR}/include/MKCDE/System.hpp
                       ${PROJECT_SOURCE_DIR}/include/MKCDE/System
                       $<TARGET_FILE_DIR:MKCDE>/Headers)

if(MKCDE_BUILD_GRAPHICS)
    add_custom_command(TARGET MKCDE POST_BUILD COMMAND cp -r
                        ${PROJECT_SOURCE_DIR}/include/MKCDE/Graphics.hpp
                        ${PROJECT_SOURCE_DIR}/include/MKCDE/Graphics
                        $<TARGET_FILE_DIR:MKCDE>/Headers)
endif()

if(MKCDE_BUILD_UTILS)
    add_custom_command(TARGET MKCDE POST_BUILD COMMAND cp -r
                        ${PROJECT_SOURCE_DIR}/include/MKCDE/Utils.hpp
                        ${PROJECT_SOURCE_DIR}/include/MKCDE/Utils
                        $<TARGET_FILE_DIR:MKCDE>/Headers)
endif()
#end headers

set_target_properties(MKCDE PROPERTIES INSTALL_NAME_DIR "@rpath")
if(NOT CMAKE_SKIP_BUILD_RPATH)
    if (CMAKE_VERSION VERSION_LESS 3.9)
        set_target_properties(MKCDE PROPERTIES BUILD_WITH_INSTALL_RPATH TRUE)
    else()
        set_target_properties(MKCDE PROPERTIES BUILD_WITH_INSTALL_NAME_DIR TRUE)
    endif()
endif()
install(TARGETS MKCDE
        FRAMEWORK DESTINATION "."
        COMPONENT mik)

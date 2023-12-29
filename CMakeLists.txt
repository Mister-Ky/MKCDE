cmake_minimum_required(VERSION 3.16)

if(POLICY CMP0141)
    cmake_policy(SET CMP0141 NEW)
endif()

project(MKCDE LANGUAGES CXX)

set(BUILD_CONFIGURATION "." CACHE STRING "Build configuration")

if(NOT BUILD_CONFIGURATION MATCHES "release" AND NOT BUILD_CONFIGURATION MATCHES "debug")
    message(FATAL_ERROR "Invalid build configuration. Please choose 'release' or 'debug'.")
endif()

if(NOT BUILD_CONFIGURATION MATCHES "x86" AND NOT BUILD_CONFIGURATION MATCHES "x64")
    message(FATAL_ERROR "Invalid architecture. Please choose 'x86' or 'x64'.")
endif()

if(NOT BUILD_CONFIGURATION MATCHES "static" AND NOT BUILD_CONFIGURATION MATCHES "dynamic")
    message(FATAL_ERROR "Invalid build type. Please choose 'static' or 'dynamic'.")
endif()

if(BUILD_CONFIGURATION MATCHES "release")
    set(BUILD_TYPE "RELEASE")
elseif(BUILD_CONFIGURATION MATCHES "debug")
    set(BUILD_TYPE "DEBUG")
endif()

if(BUILD_CONFIGURATION MATCHES "x86")
    set(ARCHITECTURE "x86")
elseif(BUILD_CONFIGURATION MATCHES "x64")
    set(ARCHITECTURE "x64")
endif()

if(BUILD_CONFIGURATION MATCHES "static")
    set(BUILD_KIND "STATIC")
elseif(BUILD_CONFIGURATION MATCHES "dynamic")
    set(BUILD_KIND "SHARED")
endif()

file(GLOB_RECURSE SOURCES 
    "src/*.cpp"
    "src/*.hpp"
    "src/*.inl"
    "src/*.cxx"
    "src/*.hxx"
    "src/*.ixx"
    "src/*.cc"
    "src/*.hh"
    "src/*.C"
    "src/*.H"
)
add_library(MKCDE ${SOURCES})
target_include_directories(MKCDE PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

set_target_properties(MKCDE PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${BUILD_TYPE}-${ARCHITECTURE}-${BUILD_KIND}
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${BUILD_TYPE}-${ARCHITECTURE}-${BUILD_KIND}
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${BUILD_TYPE}-${ARCHITECTURE}-${BUILD_KIND}
)
message(STATUS "Build configuration: ${BUILD_TYPE}-${ARCHITECTURE}-${BUILD_KIND}")

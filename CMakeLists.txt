cmake_minimum_required(VERSION 3.16)

if(POLICY CMP0141)
    cmake_policy(SET CMP0141 NEW)
endif()

project(MKCDE LANGUAGES CXX)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

set(BUILD_CONFIGURATION_RELEASE BOOL "release mkcde")
set(BUILD_CONFIGURATION_DEBUG BOOL "debug mkcde")
set(BUILD_CONFIGURATION_X86 BOOL "x86 mkcde")
set(BUILD_CONFIGURATION_X64 BOOL "x64 mkcde")
set(BUILD_CONFIGURATION_STATIC BOOL "static mkcde")
set(BUILD_CONFIGURATION_DYNAMIC BOOL "dynamic mkcde")

if(NOT ((BUILD_CONFIGURATION_RELEASE AND NOT BUILD_CONFIGURATION_DEBUG) OR
        (NOT BUILD_CONFIGURATION_RELEASE AND BUILD_CONFIGURATION_DEBUG)))
    message(FATAL_ERROR "MKCDE : Please choose either 'Release' or 'Debug' build configuration.")
endif()
if(NOT ((BUILD_CONFIGURATION_X86 AND NOT BUILD_CONFIGURATION_X64) OR
        (NOT BUILD_CONFIGURATION_X86 AND BUILD_CONFIGURATION_X64)))
    message(FATAL_ERROR "MKCDE : Please choose either 'x86' or 'x64' architecture.")
endif()
if(NOT ((BUILD_CONFIGURATION_STATIC AND NOT BUILD_CONFIGURATION_DYNAMIC) OR
        (NOT BUILD_CONFIGURATION_STATIC AND BUILD_CONFIGURATION_DYNAMIC)))
    message(FATAL_ERROR "MKCDE : Please choose either 'Static' or 'Dynamic' build type.")
endif()

if(BUILD_CONFIGURATION_RELEASE)
    set(BUILD_TYPE "RELEASE")
elseif(BUILD_CONFIGURATION_DEBUG)
    set(BUILD_TYPE "DEBUG")
endif()
if(BUILD_CONFIGURATION_X86)
    set(ARCHITECTURE "x86")
elseif(BUILD_CONFIGURATION_X64)
    set(ARCHITECTURE "x64")
endif()
if(BUILD_CONFIGURATION_STATIC)
    set(BUILD_KIND "STATIC")
elseif(BUILD_CONFIGURATION_DYNAMIC)
    set(BUILD_KIND "SHARED")
endif()

file(GLOB_RECURSE SOURCES 
    "src/MKCDE/*.cpp"
    "src/MKCDE/*.hpp"
    "src/MKCDE/*.inl"
    "src/MKCDE/*.cxx"
    "src/MKCDE/*.hxx"
    "src/MKCDE/*.ixx"
    "src/MKCDE/*.cc"
    "src/MKCDE/*.hh"
    "src/MKCDE/*.C"
    "src/MKCDE/*.H"
)
add_library(MKCDE ${BUILD_KIND} ${SOURCES})
target_compile_features(MKCDE PRIVATE cxx_std_17)
target_include_directories(MKCDE PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)
message(STATUS "MKCDE : Build configuration: ${BUILD_TYPE}-${ARCHITECTURE}-${BUILD_KIND}")

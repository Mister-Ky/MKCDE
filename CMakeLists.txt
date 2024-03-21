cmake_minimum_required(VERSION 3.16)

if(POLICY CMP0141)
    cmake_policy(SET CMP0141 NEW)
endif()

project(mkcde LANGUAGES CXX)


set(MKCDE_BUILD_CONFIGURATION_RELEASE FALSE CACHE BOOL "release mkcde")
set(MKCDE_BUILD_CONFIGURATION_DEBUG FALSE CACHE BOOL "debug mkcde")
set(MKCDE_BUILD_CONFIGURATION_X86 FALSE CACHE BOOL "x86 mkcde")
set(MKCDE_BUILD_CONFIGURATION_X64 FALSE CACHE BOOL "x64 mkcde")
set(MKCDE_BUILD_CONFIGURATION_STATIC FALSE CACHE BOOL "static mkcde")
set(MKCDE_BUILD_CONFIGURATION_DYNAMIC FALSE CACHE BOOL "dynamic mkcde")


if(NOT ((MKCDE_BUILD_CONFIGURATION_RELEASE AND NOT MKCDE_BUILD_CONFIGURATION_DEBUG) OR
        (NOT MKCDE_BUILD_CONFIGURATION_RELEASE AND MKCDE_BUILD_CONFIGURATION_DEBUG)))
    message(FATAL_ERROR "MKCDE : Please choose either 'Release' or 'Debug' build configuration.")
endif()
if(NOT ((MKCDE_BUILD_CONFIGURATION_X86 AND NOT MKCDE_BUILD_CONFIGURATION_X64) OR
        (NOT MKCDE_BUILD_CONFIGURATION_X86 AND MKCDE_BUILD_CONFIGURATION_X64)))
    message(FATAL_ERROR "MKCDE : Please choose either 'x86' or 'x64' architecture.")
endif()
if(NOT ((MKCDE_BUILD_CONFIGURATION_STATIC AND NOT MKCDE_BUILD_CONFIGURATION_DYNAMIC) OR
        (NOT MKCDE_BUILD_CONFIGURATION_STATIC AND MKCDE_BUILD_CONFIGURATION_DYNAMIC)))
    message(FATAL_ERROR "MKCDE : Please choose either 'Static' or 'Dynamic' build type.")
endif()


if(MKCDE_BUILD_CONFIGURATION_RELEASE)
    set(CMAKE_BUILD_TYPE Release)
    set(MKCDE_BUILD_TYPE "RELEASE")
elseif(MKCDE_BUILD_CONFIGURATION_DEBUG)
    set(CMAKE_BUILD_TYPE Debug)
    set(MKCDE_BUILD_TYPE "DEBUG")
endif()
if(MKCDE_BUILD_CONFIGURATION_X86)
    set(CMAKE_GENERATOR_PLATFORM x86)
    set(MKCDE_ARCHITECTURE "x86")
elseif(MKCDE_BUILD_CONFIGURATION_X64)
    set(CMAKE_GENERATOR_PLATFORM x64)
    set(MKCDE_ARCHITECTURE "x64")
endif()
if(MKCDE_BUILD_CONFIGURATION_STATIC)
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS OFF)
    set(MKCDE_BUILD_KIND "STATIC")
elseif(MKCDE_BUILD_CONFIGURATION_DYNAMIC)
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
    set(MKCDE_BUILD_KIND "SHARED")
endif()


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
add_library(mkcde ${MKCDE_BUILD_KIND} ${SOURCES})
target_compile_features(mkcde PRIVATE cxx_std_17)
target_include_directories(mkcde PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)
target_link_libraries(mkcde PUBLIC sfml-system sfml-window sfml-graphics ImGui-SFML)

message(STATUS "MKCDE : Build configuration: ${MKCDE_BUILD_TYPE}-${MKCDE_ARCHITECTURE}-${MKCDE_BUILD_KIND}")

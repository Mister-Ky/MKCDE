cmake_minimum_required(VERSION 3.16)

if(POLICY CMP0141)
    cmake_policy(SET CMP0141 NEW)
endif()

project(MKCDE LANGUAGES CXX)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

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
set_target_properties(MKCDE PROPERTIES LINKER_LANGUAGE CXX)
target_compile_features(MKCDE PRIVATE cxx_std_17)

cmake_minimum_required(VERSION 3.16)

if(POLICY CMP0141)
    cmake_policy(SET CMP0141 NEW)
endif()

project(MKCDE LANGUAGES CXX)

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

#target_link_libraries(MKCDE PRIVATE some_library)
